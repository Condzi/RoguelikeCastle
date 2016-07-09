#include "Frame.hpp"


void cn::Frame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (m_spriteToApplyTexture != nullptr && m_choosen)
		target.draw(*m_spriteToApplyTexture, states);
}

cn::Frame::Frame(const sf::Texture * texture, TextureManager * textMangrPtr, CutValues cv, sf::Sprite * spritePtr)
{
	m_texture = texture;
	m_textureManagerPointer = textMangrPtr;
	m_cutValues = cv;
	SetSpritePointer(spritePtr);
}

cn::Frame::~Frame()
{
	if (m_textureManagerPointer != nullptr && m_texture != nullptr)
		m_textureManagerPointer->ReturnTextureReference(*m_texture);
}

CutValues & cn::Frame::GetCutValuesReference()
{
	return m_cutValues;
}

float & cn::Frame::GetDurationReference()
{
	return m_duration;
}

bool & cn::Frame::GetChoosenReference()
{
	return m_choosen;
}

void cn::Frame::SetSpritePointer(sf::Sprite * spritePtr)
{
	m_spriteToApplyTexture = spritePtr;
	m_spriteToApplyTexture->setTexture(*m_texture);
	m_spriteToApplyTexture->setTextureRect(sf::IntRect(m_cutValues.posX, m_cutValues.posY, m_cutValues.sizeX, m_cutValues.sizeY));
}

void cn::Frame::SetTexturePointer(const sf::Texture * texture)
{
	if (m_texture != nullptr && m_textureManagerPointer != nullptr)
		m_textureManagerPointer->ReturnTextureReference(*m_texture);

	m_texture = texture;
}

void cn::Frame::SetTextureManagerPointer(TextureManager * textureManagerPtr)
{
	m_textureManagerPointer = textureManagerPtr;
}
