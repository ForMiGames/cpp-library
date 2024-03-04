#pragma once
#ifndef _ANIMTEXT_V2_H
#define _ANIMTEXT_V2_H

#include <string>
#include <Windows.h>
using uint16_t = unsigned short;

// Instructions:
//
// Inside the classes use: 
// Anim::AnimText ObjectName = Anim::AnimText(delay);
// Or
// Anim::AnimText ObjectName;
//
// Outside of classes, use the previous or:
// Anim::AnimText ObjectName(delay);
//
// Use: 
// ObjectName << Message;   
// Or
// ObjectName.Print("Message");
//

// Developed by ForMig
namespace Anim
{
	// Developed by ForMig
	class AnimText
	{
	public:

		// Default delay 45ms
		AnimText()
		{
			_delaySleep = 45;
		}

		// Delay in ms
		AnimText(const uint16_t delay)
			:_delaySleep(delay)
		{
		}

		// Animated output
		void Print(const std::string& message)
		{
			for (unsigned short i = 0; i < message.length(); ++i) {
				std::cout << message[i];
				Sleep(_delaySleep);
			}
		}

		//Time in ms
		void setDelay(uint16_t time)
		{
			_delaySleep = time;
		}

		uint16_t getDelay()
		{
			return _delaySleep;
		}

		void EndLine()
		{
			Sleep(_delaySleep);
			std::cout << "\n";
		}



		friend void operator << (AnimText& out, const char message[]);
		friend void operator << (AnimText& out, std::string message);

		template <class T>
		friend void operator << (AnimText& out, const T& message);

		AnimText operator=(const uint16_t& delay);


	private:
		uint16_t _delaySleep;
	};

	// Animated output type const char
	void operator << (AnimText& out, const char message[])
	{
		for (unsigned short i = 0; i < strlen(message); ++i) {
			std::cout << message[i];
			Sleep(out.getDelay());
		}
	}

	void operator << (AnimText& out, std::string message)
	{
		out.Print(message);
	}

	// Animated output 
	template <class T>
	void operator << (AnimText& out, const T& message)
	{
		out.Print(std::to_string(message));
	}

	// Setup delay in ms
	AnimText AnimText::operator=(const uint16_t& delay)
	{
		this->setDelay(delay);
		return *this;
	}

}


#endif // !_ANIMTEXT_V1_H
