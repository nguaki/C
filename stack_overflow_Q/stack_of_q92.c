#include <stdint.h>
#include <iostream>
#include <stdlib.h>

class RxJoystick {

    public:
        RxJoystick(uint8_t channel = 0);
        RxJoystick* getChannel(uint8_t ch);
        uint8_t getChannelIdx();

    protected:
        uint8_t channel;
        static RxJoystick* channels[];
};

RxJoystick* RxJoystick::channels[6];

RxJoystick::RxJoystick(uint8_t ch): channel(ch) 
{
    uint8_t i;
    for( i=0; i<6; i++)
        this->channels[i] = (RxJoystick *)(sizeof(RxJoystick));
}

RxJoystick* RxJoystick::getChannel(uint8_t ch) {
    channels[ch]->channel = ch;
    return channels[ch];
}

uint8_t RxJoystick::getChannelIdx() { 
    return this->channel;
}

int main() {
    RxJoystick rxj;
    std::cout << rxj.getChannel(1)->getChannelIdx() << std::endl;
    return 0;
}