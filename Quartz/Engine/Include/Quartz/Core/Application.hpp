// Copyright 2019 Genten Studios
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
// following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the 
// following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
// following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
// products derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED 
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY 
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH 
// DAMAGE.

#pragma once

#include <Quartz/Core/Core.hpp>
#include <Quartz/Core/Graphics/IWindow.hpp>
#include <Quartz/Core/Utilities/Logger.hpp>

namespace qz
{
	struct ApplicationRequirements
	{
		std::string windowTitle;
		int windowWidth = 1280;
		int windowHeight = 720;

		std::string logFilePath = "Quartz.log";
		utils::LogVerbosity logVerbosity = utils::LogVerbosity::INFO;
	};

	struct ApplicationData
	{
		gfx::IWindow* window = nullptr;

		ApplicationData() = default;
		~ApplicationData() = default;
	};

	class Application
	{
	public:
		Application() = default;
		virtual ~Application() = default;

		virtual const ApplicationRequirements* getAppRequirements() = 0;
		virtual void setAppData(ApplicationData* appData) = 0;

		virtual void run() = 0;
	};

	Application* createApplication();
}

