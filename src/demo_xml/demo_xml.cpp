//
// Created by jefer on 2020/4/5.
//

#include "demo_xml.h"
using namespace std;
void createXml() {
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> *rot;
    rot = doc.allocate_node(rapidxml::node_pi, doc.allocate_string(R"(xml version="1.0" encoding="utf-8")"));
    doc.append_node(rot);

    rapidxml::xml_node<> *node = doc.allocate_node(rapidxml::node_element, "config", "information");
    doc.append_node(node);

    rapidxml::xml_node<> *color = doc.allocate_node(rapidxml::node_element, "color", nullptr);
    node->append_node(color);
    color->append_node(doc.allocate_node(rapidxml::node_element, "red", "0.1"));
    color->append_node(doc.allocate_node(rapidxml::node_element, "green", "0.2"));
    color->append_node(doc.allocate_node(rapidxml::node_element, "blue", "0.3"));

    rapidxml::xml_node<> *size = doc.allocate_node(rapidxml::node_element, "size", nullptr);
    size->append_node(doc.allocate_node(rapidxml::node_element, "x", "1920"));
    size->append_node(doc.allocate_node(rapidxml::node_element, "y", "1080"));
    node->append_node(size);

    rapidxml::xml_node<> *mode = doc.allocate_node(rapidxml::node_element, "mode", "screen mode");
    mode->append_attribute(doc.allocate_attribute("fullscreen", "false"));
    node->append_node(mode);

    std::string text;
    rapidxml::print(std::back_inserter(text), doc, 0);

    printf("%s", text.c_str());
}

void readXml() {
    rapidxml::xml_document<> doc;
    char szBuf[] = "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n"
                   "<config>\n"
                   "        <color>\n"
                   "                <red>0.1</red>\n"
                   "                <green>0.2</green>\n"
                   "                <blue>0.3</blue>\n"
                   "        </color>\n"
                   "        <size>\n"
                   "                <x>1920</x>\n"
                   "                <y>1080</y>\n"
                   "        </size>\n"
                   "        <mode fullscreen=\"false\">screen mode</mode>\n"
                   "</config>";
    doc.parse<0>(szBuf);
//    std::cout << doc.name() << std::endl;
    rapidxml::xml_node<> *root = doc.first_node();
    cout<<root->name()<<endl;
}


int main() {
//    createXml();
    readXml();
    return 0;
}