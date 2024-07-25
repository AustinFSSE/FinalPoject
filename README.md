Space Rocks Game
Overview
Space Rocks is a simple space-themed game developed using Raylib, a C library for creating games. This project features a spaceship, aliens, and laser mechanics, and it includes instructions for setting up and running the project using Visual Studio Community and Visual Studio Code.
Table of Contents
•	Prerequisites
•	Installation Instructions
o	Visual Studio Community
o	Visual Studio Code
•	Usage
•	License
•	Acknowledgments
Prerequisites
•	Windows Operating System
•	Visual Studio Community or Visual Studio Code
•	Raylib Library (see installation instructions below)
Installation Instructions
Visual Studio Community
1.	Download and Install Visual Studio Community
[Option 1] - Download and install Visual Studio Community from the official website. During installation, ensure you select the "Desktop development with C++" workload.
2.	Download Raylib
Download the latest stable Raylib release from the Raylib GitHub Releases page. Choose the Windows ZIP file.
3.	Extract Raylib
Extract the downloaded ZIP file to a directory of your choice (e.g., C:\raylib).
4.	Create a New Project
o	Open Visual Studio Community.
o	Go to File -> New -> Project.
o	Select Empty Project under the C++ category and click Next.
o	Name your project and choose a location, then click Create.
5.	Configure Project Properties
o	Right-click on the project in the Solution Explorer and select Properties.
o	Navigate to Configuration Properties -> VC++ Directories.
	Add C:\raylib\include to Include Directories.
	Add C:\raylib\lib to Library Directories.
o	Navigate to Configuration Properties -> Linker -> Input.
	Add raylib.lib to Additional Dependencies.
6.	Add Source Files
o	Add your .cpp and .h files to the Source Files and Header Files folders in Solution Explorer.
7.	Build and Run
o	Build the project by selecting Build -> Build Solution.
o	Run the project by selecting Debug -> Start Debugging.
[Option 2] – Clone Raylib Repository
1.	git clone https://github.com/Microsoft/vcpkg.git
2.	cd vcpkg
3.	./bootstrap-vcpkg.bat
4.	./vcpkg integrate install
5.	./vcpkg install raylib
Visual Studio Code
1.	Download and Install Visual Studio Code
Download and install Visual Studio Code from the official website.
2.	Download Raylib
Download the latest stable Raylib release from the Raylib GitHub Releases page. Choose the Windows ZIP file.
3.	Extract Raylib
Extract the downloaded ZIP file to a directory of your choice (e.g., C:\raylib).
4.	Install Extensions
o	Open Visual Studio Code.
o	Install the C/C++ extension by Microsoft from the Extensions view (Ctrl+Shift+X).
5.	Configure Build Tasks
Create a .vscode directory in your project root and add a tasks.json file with the following content:
1.	Adjust the paths to the raylib directory as needed.
2.	Configure Include Path
Create a c_cpp_properties.json file in the .vscode directory with the following content:
3.	Build and Run
o	Open a source file in Visual Studio Code.
o	Press Ctrl+Shift+B to build the project.
o	To run the executable, open a terminal (Ctrl+``) and navigate to the build directory. Execute the program by typing ./<filename>.exe`.
Usage
•	To build and run the game, follow the setup instructions for your chosen IDE.
•	Ensure that all necessary Raylib library files are correctly referenced in your project configuration.
License
This project is licensed under the MIT License. See the LICENSE file for details.
Acknowledgments
•	Raylib - A simple and easy-to-use library for creating games.

