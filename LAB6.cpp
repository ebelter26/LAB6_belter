#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	Color greenscreen;

	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			//sets the color of a pixel to the variable backgroundC
			Color backgroundC = backgroundImage.getPixel(x, y);

			//identifies the greenscreen color
			if (x==0 && y==0) {
				greenscreen = foregroundImage.getPixel(x, y);
			}
			//if the foreground is the greenscreen color, it sets the pixel to the color of the background at that pixel
			if (foregroundImage.getPixel(x,y) == greenscreen) {
				foregroundImage.setPixel(x, y, backgroundC);
			}
		}
	}
	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}


//if green

//corner pixel
//set color to greenscreen = corner pixel (getPixel)