#pragma once
#include "TextureManager.hpp"
#include "CutValues.hpp"


namespace cn
{
	class Frame :
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	public:
		Frame(const sf::Texture * texture = nullptr, TextureManager * textMangrPtr = nullptr, CutValues cv = CutValues(), sf::Sprite * spritePtr = nullptr);
		~Frame();

		CutValues & GetCutValuesReference();
		float & GetDurationReference();
		bool & GetChoosenReference();

		//	Sprite that will be displayed with Frame texture
		void SetSpritePointer(sf::Sprite * spritePtr);
		void SetTexturePointer(const sf::Texture * texture);
		void SetTextureManagerPointer(TextureManager * textureManagerPtr);

	private:
		TextureManager * m_textureManagerPointer;
		const sf::Texture * m_texture;
		sf::Sprite * m_spriteToApplyTexture;
		CutValues m_cutValues;
		//	Frame time on screen in seconds
		float m_duration;
		//	If it is it's 'time' in Animator then change m_spriteToApplyTexture texture
		//	To Frame texture
		bool m_choosen;
	};

}

