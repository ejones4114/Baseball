//
//  CurlObject.cpp
//  Baseball
//
//  Created by Eric Jones on 11/11/22.
//

#include <stdio.h>
#include <string>
#include <curl/curl.h>
#include <gumbo.h>





   class CurlObject {
   public:
      
       CurlObject (std::string url) {
           curl = curl_easy_init();
           if (!curl) {
               throw std::string ("Curl did not initialize.");
           }

           curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObject::curlWriter);
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
      
      std::string cleantext(GumboNode* node) {
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
      
  protected:
      CURL * curl;
      std::string curlBuffer;
  };
