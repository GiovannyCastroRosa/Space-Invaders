#include "animation_renderer.h"


namespace space_invaders {
    Animation_Renderer::Animation_Renderer(int frameWidth, int frameHeight,
        float entityWidth, float entityHeight,
        const sf::Texture& spriteSheet)
        : m_frameWidth(frameWidth)
        , m_frameHeight(frameHeight)
    {
        m_entity.setSize({ entityWidth, entityHeight });
        m_entity.setTexture(&spriteSheet);
    }

    void Animation_Renderer::nextFrame()
    {
        m_currentFrame++;
    }

    void Animation_Renderer::renderEntity(sf::RenderTarget& renderer, int type,
        const sf::Vector2f& position)
    {
        // Calculate texture coords
        int texLeft = (m_currentFrame % 2) * m_frameWidth;
        int texTop = (type * m_frameHeight);

        // Reposition and draw sprite
        m_entity.setPosition(position);
        m_entity.setTextureRect({ texLeft, texTop, m_frameWidth, m_frameHeight });
        renderer.draw(m_entity);
    }
}