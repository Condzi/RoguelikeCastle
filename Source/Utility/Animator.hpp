#pragma once
#include "Frame.hpp"


namespace cn
{
	class Animator :
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	public:
		Animator(float speed = 1.f, bool loop = false, bool play = false);
		~Animator();

		bool & GetLoopedReference();
		float & GetSpeedReference();

		bool AddFrame(const Frame & frame);
		bool DelFrame(const size_t & id);

		bool Start();
		bool Stop();
		bool Update();

	private:
		sf::Clock * m_clock;
		std::vector<Frame> m_frames;
		size_t m_currentFrame;
		//	Animation speed 0.1f to 2.f
		float m_speed;
		bool m_looped;
		bool m_play;
	};
}

