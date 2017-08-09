#ifndef TEXTUREATLAS_H
#define TEXTUREATLAS_H

#include <SFML/Graphics.hpp>
#include <map>

#include "QuestiaEng/ResourceManager/ResourceManager.h"
#include "QuestiaEng/Utl/Type/Rect.h"

struct TextureAtlasData
{
    //ctor
    TextureAtlasData(sf::Texture* texture) : texture(texture) {}

    std::map<std::string, utl::IntRect> textureCoords;
    sf::Texture* texture;
};

class TextureAtlas
{
public:
    TextureAtlas(ResourceManager& resourceManager);
    ~TextureAtlas();

    //returns if there is space, otherwise make another one
    bool addTexture(const std::string& name, const std::string& fileLocation);

    //returns the textures and coords of texture bounds
    TextureAtlasData compileTextures(const std::string& textureName);

    //clear everything
    void reset()
    {
        maxWidth = 0;
        maxHeight = 0;
        maxWidthCurrentLayer = 0;
        layers = 1;
        textureList.clear();
        textureLocations.clear();
    }

private:
    ResourceManager* resourceManager = nullptr;

    //Depending on graphics card, game minimum being 512 x 512
    unsigned int maxTextureSize = sf::Texture::getMaximumSize();
    //used for checking layer space left
    unsigned int maxWidth = 0;
    unsigned int maxWidthCurrentLayer = 0;
    unsigned int maxHeight = 0;
    //used for current layer space left
    int layers = 1;

    //stores all textures
    std::vector<std::pair <std::string, sf::Texture*> > textureList;
    //stores texture locations for deleting after copying
    std::vector<std::string> textureLocations;

    sf::Texture textureResult;
};

#endif // TEXTUREATLAS_H
