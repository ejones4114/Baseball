//
//  main.cpp
//  Baseball
//
//  Created by Eric Jones on 11/10/22.
//


#include <iostream>
#include <gumbo.h>
#include <curl/curl.h>
#include <string>

using namespace std;



static std::string cleantext(GumboNode* node) {
  if (node->type == GUMBO_NODE_TEXT) {
    return std::string(node->v.text.text);
  } else if (node->type == GUMBO_NODE_ELEMENT &&
             node->v.element.tag != GUMBO_TAG_SCRIPT &&
             node->v.element.tag != GUMBO_TAG_STYLE) {
    std::string contents = "";
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
      const std::string text = cleantext((GumboNode*) children->data[i]);
      if (i != 0 && !text.empty()) {
        contents.append(" ");
      }
      contents.append(text);
    }
    return contents;
  } else {
    return "";
  }
}

   class CurlObj {
   public:
       /**
        * @brief Constructor for a curl object.
        *
        * @param url The url of the page to scrape.
        */
       CurlObj (std::string url) {
           curl = curl_easy_init();
           if (!curl) {
               throw std::string ("Curl did not initialize.");
           }

           curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
           curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
           curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
           curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
           curl_easy_perform(curl);
       };
      
      static int curlWriter(char *data, int size, int nmemb, std::string *buffer) {
          int result = 0;
          if (buffer != NULL) {
              buffer->append(data, size * nmemb);
              result = size * nmemb;
          }
          
          return result;
      }
      
      std::string getData() {
          return curlBuffer;
      }
      
  protected:
      CURL * curl;
      std::string curlBuffer;
  };
   
   
int main() {
   
   CurlObj *curl = new CurlObj("https://www.baseball-reference.com/teams/SEA/2022.shtml");
   string info = curl->getData();
   
   GumboOutput *out = gumbo_parse(info.c_str());

   std::cout << cleantext(out->root) << std::endl;
   gumbo_destroy_output(&kGumboDefaultOptions, out);
   
   return 0;
}
