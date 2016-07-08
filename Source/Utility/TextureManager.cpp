#include "TextureManager.hpp"

void cn::TextureManager::deleteUnusedPaths()
{
	bool helpBool = false;

	for (size_t i = 0; i < m_texturePaths.size(); ++i)
	{
		helpBool = false;
		for (size_t j = 0; j < m_fixedTextures.size(); ++j)
		{
			if (m_fixedTextures[j].GetPath() == m_texturePaths[i])
			{
				helpBool = true;
				break;
			}
		}

		if (!helpBool)
			m_texturePaths.erase(m_texturePaths.begin(), m_texturePaths.begin() + i);
	}
}

void cn::TextureManager::deleteTexturesWithNoReferences()
{
	for (size_t i = 0; i < m_fixedTextures.size(); ++i)
		if (!m_fixedTextures[i].GetReferenceCount())
			m_fixedTextures.erase(m_fixedTextures.begin(), m_fixedTextures.begin() + i);
}

bool cn::TextureManager::reloadTextures()
{
	m_fixedTextures.resize(m_texturePaths.size());

	for (size_t i = 0; i < m_fixedTextures.size(); ++i)
	{
		if (m_fixedTextures[i].GetPath() == "")
			if (!m_fixedTextures[i].LoadTextureFromFile(m_texturePaths[i]))
			{
#ifdef DEBUG
				std::cout << "[$DEBUG] Cannot load texture from path\"" << m_texturePaths[i] << "\".\n";
#endif // DEBUG
				return false;
			}
	}

	return true;
}

cn::TextureManager::TextureManager()
{
}

cn::TextureManager::~TextureManager()
{
}

bool cn::TextureManager::AddPath(const std::string & path)
{
	if (path == "" || path == " ")
		return false;

	for (std::string var : m_texturePaths)
		if (var == path)
			return false;

	m_texturePaths.push_back(path);
	
	return true;
}

bool cn::TextureManager::DelPath(const std::string & path)
{
	if (path == "" || path == " ")
		return false;

	for (size_t i = 0; i < m_texturePaths.size(); ++i)
		if (m_texturePaths.at(i) == path)
		{
			m_texturePaths.erase(m_texturePaths.begin(), m_texturePaths.begin() + i);
			return true;
		}

	return false;
}

const sf::Texture & cn::TextureManager::GetTextureReference(const std::string & texturePath)
{
	for (cn::TextureFixed var : m_fixedTextures)
		if (var.GetPath() == texturePath)
			return var.GetTextureReference();

	return sf::Texture();
}

bool cn::TextureManager::ReturnTextureReference(const sf::Texture & texture)
{
	for (cn::TextureFixed var : m_fixedTextures)
		if (var.ReturnTextureReference(texture))
			return true;

#ifdef DEBUG
	std::cout << "\n[$DEBUG] Cannot return texture reference!\n\n";
#endif // DEBUG

	return false;
}

void cn::TextureManager::Reload()
{
#ifdef DEBUG
	std::cout << "[#DEBUG] TextureManager::Reload started. \n";
#endif // DEBUG

	deleteUnusedPaths();
	deleteTexturesWithNoReferences();
	reloadTextures();

#ifdef DEBUG
	std::cout << "[#DEBUG] TextureManager::Reload end. \n";
#endif // DEBUG
}
