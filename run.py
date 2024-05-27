import subprocess
import os

def run_project():
    # Change directory to build_cuda
    os.chdir("build_cuda")

    # Run cmake
    cmake_command = [
        "cmake", "..",
        "-G", "Visual Studio 17 2022",
        "-DCMAKE_C_COMPILER=C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe",
        "-DCMAKE_CXX_COMPILER=C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.37.32822/bin/Hostx64/x64/cl.exe"
    ]
    subprocess.run(cmake_command, shell=True, check=True)

    # Run msbuild
    msbuild_command = ["msbuild", "PC-MAX.sln"]
    subprocess.run(msbuild_command, shell=True, check=True)

    # Go back to the root directory (PC-Max)
    os.chdir("..")

    # Run the executable
    subprocess.run([".\\build_cuda\\Debug\\main.exe"], shell=True, check=True)

if __name__ == "__main__":
    run_project()
