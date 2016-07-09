#include "Animator.hpp"

void cn::Animator::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (m_play)
		target.draw(m_frames[m_currentFrame], states);
}

cn::Animator::Animator(float speed, bool loop, bool play)
{
	m_currentFrame = 0;
	m_speed = speed;
	m_looped = loop;
	m_play = play;
	m_clock = nullptr;
}

cn::Animator::~Animator()
{
	if (m_clock != nullptr)
		delete m_clock;
}

bool & cn::Animator::GetLoopedReference()
{
	return m_looped;
}

float & cn::Animator::GetSpeedReference()
{
	return m_speed;
}

bool cn::Animator::AddFrame(const Frame & frame)
{
	if (&frame == nullptr)
		return false;

	m_frames.push_back(frame);
	return true;
}

bool cn::Animator::DelFrame(const size_t & id)
{
	if (id > m_frames.size() - 1)
		return false;

	m_frames.erase(m_frames.begin(), m_frames.begin() + id);
	return true;
}

bool cn::Animator::Start()
{
	if (m_frames.size() == 0)
		return false;

	if (m_speed <= 0 || m_speed > 2.f)
		m_speed = 1.f;

	if (m_clock == nullptr)
		m_clock = new sf::Clock;
	else
		m_clock->restart();

	m_currentFrame = 0;
}

bool cn::Animator::Stop()
{
	if (!m_play)
		return false;
	if (m_looped)
		return false;

	m_play = false;
	return true;
}

bool cn::Animator::Update()
{
	if (!m_play)
		return false;

	float timeEleapsed = 0.f;

	for (size_t i = 0; i < m_currentFrame; ++i)
		timeEleapsed += m_frames[i].GetDurationReference();

	if (m_clock->getElapsedTime().asSeconds() > timeEleapsed)
		m_currentFrame++;

	if (m_currentFrame >= m_frames.size() - 1)
		return false;

	Stop();

	return true;
}
