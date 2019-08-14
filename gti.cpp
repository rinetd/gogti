// extern "C" {
// 	#include "gti_c.h"
// }

#include <unistd.h>
#include <fstream>
#include <cstring>
#include <iostream>
// #include <memory>
// #include <string>
#include "Include/GTILib.h"
#include "Include/GtiLog.h"

#include "gti.h"

using namespace std;

static unique_ptr<char[]> file_to_buffer(char *filename, int *sizeptr)
{
    std::ifstream fin(filename, ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout << "Could not open file: " << filename << endl;
        exit(-1);
    }

    fin.seekg(0, std::ios::end);
    *sizeptr = fin.tellg();
    fin.seekg(0, std::ios::beg);

    unique_ptr<char[]> buffer(new char[*sizeptr]);

    fin.read((char *)buffer.get(), *sizeptr);
    fin.close();
    return move(buffer);
}

static void dump_buffer(const string &filename, char *buf, int size)
{
    std::ofstream fout(filename, ios::out | ios::binary);
    if (!fout.is_open())
    {
        cout << "Could not open file: " << filename << endl;
        exit(-1);
    }
    fout.write(buf, size);
    fout.close();
}

int run()
{

    //   int loops=1;
    // if(argc<3)
    // {
    //     cout<<"usage: "<<argv[0]<<" GTI_model_file image_file [loops]"<<endl;
    //     cout<<"   Ex: "<<argv[0]<<" ../Models/2801/gti_gnet3_fc20_2801.model ../Data/Image_lite/bridge_c20.bin"<<endl;
    //     cout<<"       "<<argv[0]<<" ../Models/2803/gti_mnet_fc40_2803.model ../Data/Image_lite/swimming_c40.jpg 10"<<endl;

    //     exit(-1);
    // }
    // cout << mfile<<endl;
    // cout << tfile<<endl;
    char mfile[] = "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model";
    // var argv =[]string{"/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model", "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.jpg"}
    //char tfile[] = "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.jpg";
    //    void * model= GTI_NewModel(mfile);
    const char *v = GtiGetSDKVersion();
    cout << "version" << v << endl;

    GtiModel *model = GtiCreateModel("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model");
    // int i =0;
    // char * p=(char * )model;
    // for (i=0;i<1000;i++){
    //     cout << *p++;
 
    // }

  //Read 224x224 BGR plannar format image data from file
    std::ifstream fin("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.bin", ios::in | ios::binary );

    if(!fin.is_open())
    {
        cout<<"Could not open file: "<< "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.bin" << endl; 
        exit(-1);
    }

    fin.seekg(0,std::ios::end);
    size_t filesize=fin.tellg();
    fin.seekg(0,std::ios::beg);

    cout << filesize;

    // unique_ptr<char[]> buf(new char[filesize]);
    // fin.read((char *)buf.get(), filesize);

    char *buf=new char[filesize];
    fin.read(buf, filesize);
    fin.close();
    
    // GtiTensor *tensor = new(GtiTensor);
    // tensor->height=1;
    // tensor->width=1;
    // tensor->depth=filesize;
    // tensor->buffer=buf;

 GtiTensor tensor ;
    tensor.height=1;
    tensor.width=1;
    tensor.depth=filesize;
    tensor.buffer=buf;
    // cout << "brefor tensor" << tensor.format << endl;
    // cout << "brefor buffer" << tensor.buffer << endl;

    // -------------------------
    // int filesize = 0;
    // unique_ptr<char[]> buf = file_to_buffer( "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.bin", &filesize);



    // GtiTensor *tensor = new (GtiTensor);
    // tensor->height = 1;
    // tensor->width = 1;
    // tensor->depth = filesize;
    // tensor->buffer = buf.get();

    // cout << (char * )tensor->buffer<<endl;
    // p=(char * )tensor->buffer;
    // for (i=0;i<100;i++){
    //     cout << *p++;
 
    // }

    // cout << "start Evaluate" << tensor;

    GtiTensor *Out = GtiEvaluate(model, &tensor);
    cout << "prediect finish" << (char *)Out->buffer<<endl;
    return 0;
}
