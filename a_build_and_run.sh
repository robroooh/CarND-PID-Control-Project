echo "Building the project"
mkdir build && cd build
echo "Built the project"
echo "Making the project"
cmake .. && make
echo "Made the project"
echo "Running the project"
./pid
echo "Done!"