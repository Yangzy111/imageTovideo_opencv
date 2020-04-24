#include<opencv2/opencv.hpp>
#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	cout << "start" << endl;
	string input = argv[1];
	string output = argv[2];
	string ext = argv[3];
	int fps = atoi(argv[4]);
	int width = atoi(argv[5]);
	int height = atoi(argv[6]);
	bool isColor = atoi(argv[7]);
	

	VideoWriter writer(output, VideoWriter::fourcc('M', 'P', '4', '2'), fps,
		Size(width, height), isColor);

	string input_path = input;
	
	std::vector<cv::String> filePaths;
	std::string img_name;

	glob(input_path + "/*." + ext, filePaths, false);
		
	size_t count = filePaths.size();
    if (count==0)
    {
        cout << "file in " << input_path << " not  exits"<<endl;
        return -1;
    }
	
	vector<string> names;

	for (int i = 0; i < count; ++i)
    {
        auto iPos = filePaths[i].find_last_of('/') + 1;
        string filename = filePaths[i].substr(iPos);
        
        string name = filename.substr(0, filename.rfind("."));
        //cout << name << endl;
		names.emplace_back(name);
    }
	sort(names.begin(), names.end(),
         [](string a, string b) {return stoi(a) < stoi(b); });
		
	for (int i = 0; i < names.size(); i++)
	{
		std::string filePath = names[i];
		cv::Mat image = cv::imread(filePath,1);
		cout << filePath << endl;
		cout << "processing..." << i + 1 << "of" << names.size() << endl;
		if (image.empty())
		{
			cout << "image " << filePath << " doesn't exist!" << endl;
			return -1;
		}
			writer.write(image);
	}
	cout << "finish" << endl;
	return 0;
}