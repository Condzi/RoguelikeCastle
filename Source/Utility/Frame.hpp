#pragma once
#include "TextureManager.hpp"
#include "CutValues.hpp"

namespace cn
{
	class Frame
	{
	public:
		Frame(const sf::Texture * texture = nullptr, TextureManager * textMangrPtr = nullptr, CutValues cv = CutValues(), sf::Sprite * spritePtr = nullptr);
		~Frame();

		CutValues & GetCutValuesReference();
		float & GetDurationValuesReference();
		
		void SetSpritePointer(sf::Sprite * spritePtr);
		void SetTextureManagerPointer(TextureManager * textureManagerPtr);

	private:
		TextureManager * m_textureManagerPointer;
		const sf::Texture * m_texture;
		sf::Sprite * m_spriteToApplyTexture;
		CutValues m_cutValues;
		//	Frame time on screen in seconds
		float m_duration;
	};

}

