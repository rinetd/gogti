package main

/*
// 这里gti的库 使用到了GTILibrary的库所以在编译的时候都要引用。
#cgo LDFLAGS: -L ${SRCDIR}/lib -lGTILibrary -ldl -lm  -pthread -lstdc++
#include "gti.h"
*/
import "C"
import (
	_ "unsafe"
	// "fmt"
)



func main(){
	// CreateModel("aaa")
	// m:=NewModel("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model")
	// m:=NewTensor("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.bin")
	// Evaluate(m,t)
	//p:=C.CString("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model")
	// defer C.free(unsafe.Pointer(p))
	//m:=C.GTI_NewModel(p)
	//str:=C.CString("/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.bin")
	//C.GTI_Predict(m, str)
	//fmt.Println(a)

	// ../Models/2801/gti_gnet3_fc20_2801.model ../Data/Image_lite/bridge_c20.bin
	// var argv =[]string{"./Models/2801/gti_gnet3_fc20_2801.model", "./Data/Image_lite/bridge_c20.bin"}
	// var argv =[]string{"/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Models/2801/gti_gnet3_fc20_2801.model", "/sdcard/GTISDK-Linux_aarch64_v4.0.1/Apps/Data/Image_lite/bridge_c20.jpg"}
	// m:=C.CString(argv[0])
	// t:=C.CString(argv[1])
	// C.run(C.int(len(argv)),m,t) //main(int argc,char**argv)

// i,err:=
C.run()
// fmt.Println(i,err)
}
