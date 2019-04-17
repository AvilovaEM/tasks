#include<iostream>
#include<exception>
#include<string>

std::string AskTimeServer() {
    throw std::system_error();
}

class TimeServer {
public:
    std::string GetCurrentTime() {
        try {
          LastFetchedTime = AskTimeServer();
          return LastFetchedTime;
        } catch (std::system_error& e) {
            return LastFetchedTime;
        }
        catch(std::exception& e){
           throw;
        }
    }

private:
    std::string LastFetchedTime = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        for(int i = 0; i < 2; ++i)
            std::cout << ts.GetCurrentTime() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception got: " << e.what() << std::endl;
    }
    return 0;
}
