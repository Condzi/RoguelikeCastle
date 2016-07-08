#pragma once
#include "TextureFixed.hpp"

namespace cn
{
	class TextureManager
	{
	private:
		void deleteUnusedPaths();
		void deleteTexturesWithNoReferences();
		bool reloadTextures();

	public:
		TextureManager();
		~TextureManager();

		bool AddPath(const std::string & path);
		bool DelPath(const std::string & path);

		const sf::Texture & GetTextureReference(const std::string & texturePath);
		bool ReturnTextureReference(const sf::Texture & texture);

		// Warning! This will DELETE textures with no references!
		// Also loads textures from paths
		void Reload();

	private:
		std::vector<TextureFixed> m_fixedTextures;
		std::vector<std::string> m_texturePaths;
	};
}


