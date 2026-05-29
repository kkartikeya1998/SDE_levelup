#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;


//------------------------------------------
// Product or Object Class
//------------------------------------------

class HttpRequest {
private:
    string url = "";
    string method = "GET";
    map<string, string> headers;
    string body = "";
    int timeout = 600;

    HttpRequest() {}

public:
    friend class HttpRequestBuilder;

    void execute() {
        cout << "[HttpRequest] Executing request (" << this << ") with paramters:\n";

        cout << "\tURL:\t" << url << endl;
        cout << "\tMethod:\t" << method << endl;

        for(const auto& header : headers) {
            cout << "\tHeader:\t" << header.first << ", " << header.second << endl;
        }

        if(!body.empty()){
            cout << "\tBody:\t" << body << endl;
        } 

        cout << "\tTimeout:\t" << timeout << endl;
    }
};


//------------------------------------------
// Builder Class
//------------------------------------------

class HttpRequestBuilder {
private:
    HttpRequest req;

public:
    HttpRequestBuilder& with_url(const string& val) {
        req.url = val;
        return *this;
    }

    HttpRequestBuilder& with_method(const string& val) {
        req.method = val;
        return *this;
    }

    HttpRequestBuilder& with_header(const string& key, const string& val) {
        req.headers[key] = val;
        return *this;
    }

    HttpRequestBuilder& with_timeout(int val) {
        req.timeout = val;
        return *this;
    }

    HttpRequestBuilder& with_body(const string& val) {
        req.body = val;
        return *this;
    }

    HttpRequest build() {
        if(req.url.empty()){
            throw runtime_error(
                "[HttpRequestBuilder] Cannot initialize HttpRequest without a URL!\n"
            );
        }

        if(req.method == "GET" && !req.body.empty()) {
            throw runtime_error(
                "[HttpRequestBuilder] Cannot initialize a GET request with a body!\n"
            );
        }
        
        return req;
    }
    
};


//------------------------------------------
// Client Code
//------------------------------------------
int main() {
    HttpRequest req1 = HttpRequestBuilder()
                        .with_url("https://www.google.com")
                        .with_header("Lemon", "Soda")
                        .with_header("Cola", "Candy")
                        .build();

    req1.execute();

    HttpRequest req2 = HttpRequestBuilder()
                        .with_url("https://googledoc.com")
                        .with_method("POST")
                        .with_body("Some random text to fill out the body.")
                        .with_timeout(1000)
                        .build();
    req2.execute();
    return 0;
}