#include "Frame.hpp"


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

float & cn::Frame::GetDurationValuesReference()
{
	return m_duration;
}

void cn::Frame::SetSpritePointer(sf::Sprite * spritePtr)
{
	m_spriteToApplyTexture = spritePtr;
	m_spriteToApplyTexture->setTexture(*m_texture);
	m_spriteToApplyTexture->setTextureRect(sf::IntRect(m_cutValues.posX, m_cutValues.posY, m_cutValues.sizeX, m_cutValues.sizeY));
}

void cn::Frame::SetTextureManagerPointer(TextureManager * textureManagerPtr)
{
	m_textureManagerPointer = textureManagerPtr;
}
