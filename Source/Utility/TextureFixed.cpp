#include "TextureFixed.hpp"

cn::TextureFixed::TextureFixed()
{
	m_texture = nullptr;
	m_pathToTexture = "";
	m_referenceCounter = 0;
}

cn::TextureFixed::~TextureFixed()
{
	if (m_texture != nullptr)
		delete m_texture;
}

const sf::Texture & cn::TextureFixed::GetTextureReference()
{
#ifdef DEBUG
	std::cout << "[#DEBUG] Reference to texture \"" << m_pathToTexture << "\" sharded. Total references: " << m_referenceCounter + 1 << ".\n";
#endif // DEBUG
	m_referenceCounter++;
	return *m_texture;
}


uint16_t cn::TextureFixed::GetReferenceCount()
{
	return m_referenceCounter;
}

std::string cn::TextureFixed::GetPath()
{
	return m_pathToTexture;
}

bool cn::TextureFixed::ReturnTextureReference(const sf::Texture & texture)
{
	if (this->m_texture == &texture)
	{

#ifdef DEBUG
		std::cout << "[#DEBUG] Reference to texture \"" << m_pathToTexture << "\" returned. Total references: " << m_referenceCounter - 1 << ".\n";
#endif // DEBUG
		
		m_referenceCounter--;
		return true;
	}

#ifdef DEBUG
	std::cout << "[@sDEBUG] Failed to return reference to texture \"" << m_pathToTexture << "\"\n";
#endif // DEBUG

	return false;
}

bool cn::TextureFixed::LoadTextureFromFile(const std::string & path)
{
	if (m_texture != nullptr)
	{
		delete m_texture;
		m_texture = nullptr;
	}

	m_texture = new sf::Texture;
	if (m_texture->loadFromFile(path))
		return true;

	delete m_texture;
	m_texture = nullptr;
	return false;
}

bool cn::TextureFixed::SetTexture(sf::Texture & texture)
{
	if (&texture == nullptr)
		return false;

	if (m_texture != nullptr)
	{
		delete m_texture;
		m_texture = nullptr;
	}

	m_texture = new sf::Texture(texture);
	return true;
}

bool cn::TextureFixed::SetTexturePointer(sf::Texture & texture)
{
	if (&texture == nullptr)
		return false;

	if (m_texture != nullptr)
	{
		delete m_texture;
		m_texture = nullptr;
	}

	m_texture = &texture;
	return true;
}

bool cn::TextureFixed::operator==(const cn::TextureFixed & a)
{
	return (m_referenceCounter == a.m_referenceCounter &&
		m_pathToTexture == a.m_pathToTexture);
}

bool cn::TextureFixed::operator!=(const cn::TextureFixed & a)
{
	return (operator==(a))?false:true;
}
