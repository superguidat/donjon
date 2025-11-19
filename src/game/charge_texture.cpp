#include			"donjon_master.hh"

t_bunny_response		charge_texture(const char	*file_path,
					       t_prog		*pro,
					       int32_t		i)
{
  sf::Image			img;
  const uint8_t			*pixels;

  if (!img.loadFromFile(file_path))
    {
      std::cerr << "Erreur : impossible de charger la texture" << std::endl;
      return EXIT_ON_ERROR;
    }
  pixels = img.getPixelsPtr();
  glGenTextures(1, &pro->textureID[i]);
  glBindTexture(GL_TEXTURE_2D, pro->textureID[i]);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.getSize().x, img.getSize().y, 0,
	       GL_RGBA, GL_UNSIGNED_BYTE, pixels);
  return GO_ON;
}
