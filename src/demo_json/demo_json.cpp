//
// Created by jefer on 2020/4/4.
//

#include "demo_json.h"

using namespace std;

void toJson() {
    Json::Value root, lang, email;

    root["Name"] = "jefer";
    root["Age"] = 24;

    lang[0] = "PHP";
    lang[1] = "C++";
    root["Language"] = lang;

    email["personal"] = "jeferwang@qq.com";
    email["work"] = "jeferwang@company.com";
    root["Email"] = email;

    cout << root.toStyledString() << endl;

}

void fromJson() {
    Json::Value root;
    std::string errs;
    std::string jsonStr = "{\n"
                          "        \"Age\" : 24,\n"
                          "        \"Email\" :\n"
                          "        {\n"
                          "                \"personal\" : \"jeferwang@qq.com\",\n"
                          "                \"work\" : \"jeferwang@company.com\"\n"
                          "        },\n"
                          "        \"Language\" :\n"
                          "        [\n"
                          "                \"PHP\",\n"
                          "                \"C++\"\n"
                          "        ],\n"
                          "        \"Name\" : \"jefer\"\n"
                          "}";
    Json::CharReaderBuilder readerBuilder;
//    Json::CharReader *cr = readerBuilder.newCharReader();
    unique_ptr<Json::CharReader> cr(readerBuilder.newCharReader());
    cr->parse(jsonStr.c_str(), jsonStr.c_str() + jsonStr.length(), &root, &errs);
    cout << root["Name"] << endl;
}


int main(int argc, char **argv) {
    toJson();
    fromJson();
    return 0;
}