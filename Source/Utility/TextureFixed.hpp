#pragma once
#include <SFML\Graphics.hpp>
#include "IsDebug.hpp"


namespace cn //cn = CoNdzi :)
{
	class TextureFixed
	{
	public:
		TextureFixed();
		~TextureFixed();

		const sf::Texture & GetTextureReference();
		uint16_t GetReferenceCount();
		std::string GetPath();
		bool ReturnTextureReference(const sf::Texture & texture);

		bool LoadTextureFromFile(const std::string & path);
		bool SetTexture(sf::Texture & texture);
		bool SetTexturePointer(sf::Texture & texture);

		bool operator==(const cn::TextureFixed & a);
		bool operator!=(const cn::TextureFixed & a);

	private:
		sf::Texture * m_texture;
		//	If there is no reference to this texture, 
		//	cn::TextureManager delete it in next call of 
		//	cn::TextureManger::reloadTextures
		uint16_t m_referenceCounter;
		//	Unique for every texture, it's path, helps to 
		//	identify it in cn::TextureManager
		std::string m_pathToTexture;
	};
}


