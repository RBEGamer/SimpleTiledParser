# SimpleTiledParser
A simple parser to parse maps from the TiledMapEditor (http://mapeditor.org/) into your Game.

* Tile animations
* Tile properties
* Layer properties

Currently not supported :
* Only CSV Encoding with no compression !
* No Terrain support
* No <tileset offset> tag support


Best practise is to place animated tiles in a different layer!


# INI File Parser
Parses a ini config file. With easy to use Section and Key search functions.

* #include "tmx_ini_parser.hpp"
* tmx_ini_loader* tmx_ini_loader = new tmx_ini_loader::tmx_ini_loader();
* tmx_ini_loader->load_ini_file("config.ini");
* std::string result = tmx_ini_loader->get_value("window", "window_title");
* delete tmx_ini_loader;
