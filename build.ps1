# Change directory to the build folder
cd build

# Run CMake
cmake ..

# Build the project using MSBuild
msbuild Test_Calorimeter.sln

# Change directory to the release folder
cd release

# Run the executable
.\Test_Calorimeter interactive

# Go back to the root directory
cd ..
cd ..