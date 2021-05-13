#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(){
  sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
  // sf::CircleShape shape(100.f);

  //creating the sprite to show each pixel of the fluid
  sf::Sprite sprite;
  sf::Texture texture;

  // create an empty 200x200 texture
  if (!texture.create(200, 200));

  // initializing the grid and updating the texture
  sf::Uint8* pixels = new sf::Uint8[200 * 200 * 4]; // * 4 because pixels have 4 components (RGBA)
  for(int i = 0; i< 200*200*4; i++){
    pixels[i] = 255;
  }
  texture.update(pixels);
  sprite.setTexture(texture);
  // sprite.setColor(sf::Color(0, 255, 0, 255));
  sprite.setPosition(sf::Vector2f(100.f, 100.f)); 

  // shape.setFillColor(sf::Color::Green);
  int j = 0;

  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
          window.close();
    }

    //testing pixel updating
    for(int i = 0; i< 200*200*4 && j % 100 == 0; i++){
      if(i % 4 == 0 && pixels[i] > 0) pixels[i]--;
      if((i-1) % 4 == 0 && pixels[i] > 0) pixels[i]--;
    }
    j++;
    texture.update(pixels);
    window.clear();
    window.draw(sprite);
    window.display();
  }

  return 0;
}

