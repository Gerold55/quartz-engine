#include <engine/common.hpp>

#include <engine/graphics/window.hpp>
#include <engine/graphics/opengl/texture.hpp>

#include <stb_image/stb_image.h>

#include "client/chunk.hpp"
#include "client/textures.hpp"

int main()
{
	INITLOGGER( "pheonix.log", pheonix::LogVerbosity::INFO );
	INFO( "CLIENT STARTING..." );

	pheonix::graphics::Window* window = new pheonix::graphics::Window( 1280, 720, std::string("Project Pheonix") );

	glewInit();

	glEnable( GL_DEPTH_TEST );

	int nChannels, texWidth, texHeight;
	unsigned char* data = stbi_load( "../dirt.png", &texWidth, &texHeight, &nChannels, 0);

	pheonix::graphics::opengl::Texture* dirt = new pheonix::graphics::opengl::Texture( pheonix::graphics::opengl::Texture::Target::TEXTURE2D, texWidth, texHeight, pheonix::graphics::opengl::Texture::Format::RGBA );
	std::cout << glGetError() << std::endl;
	dirt->bind( pheonix::graphics::opengl::Texture::Unit::T0 );
	std::cout << glGetError() << std::endl;

	dirt->setData( data );

	pheonix::graphics::Chunk* chunk = new pheonix::graphics::Chunk();

	DEBUG( "POPULATING CHUNK!" );
	chunk->populateChunk(16);
	DEBUG( "CHUNK POPULATED" );

	chunk->build();
	DEBUG( "CHUNK HAS BEEN BUILT!" );

	while ( !window->shouldClose() ) {
		window->pollEvents();

		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glClearColor( 0.1f, 0.3f, 0.9f, 1.0f );

		//dirt->bind( pheonix::graphics::opengl::Texture::Unit::T0 );
		std::cout << glGetError() << std::endl;

		chunk->draw();

		window->swapBuffers();
	}

	INFO( "CLIENT QUITTING" );
}
