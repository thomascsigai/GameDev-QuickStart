#include <GameObject.h>

namespace Djipi
{
	void GameObject::Render(SDL_Renderer* renderer)
	{
		SDL_FRect rect = {
			m_Transform.position.x, m_Transform.position.y,
			m_Transform.size.x, m_Transform.size.y
		};
		SDL_RenderFillRectF(renderer, &rect);

#ifndef NDEBUG
		//Debug draw colliders
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderDrawRectF(renderer, &m_Transform.collider);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
#endif
				
	}

	void GameObject::Update(double deltaTime)
	{
		Move(deltaTime);
	}

	void GameObject::Move(double deltaTime)
	{
		m_Transform.position += m_Velocity * deltaTime;
		m_Transform.UpdateCollider();
	}

	void GameObject::OnCollide(GameObject& other)
	{
		cout << m_Name << "Collided with " << other.m_Name << "." << endl;
	}

	void GameObject::HandleEvent(SDL_Event& e)
	{
		cerr << "HandleEvent method used but not implemented for GameObject " << m_Name << "." << endl;
	}
}