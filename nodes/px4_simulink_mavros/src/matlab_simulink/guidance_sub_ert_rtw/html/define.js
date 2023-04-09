function CodeDefine() { 
this.def = new Array();
this.def["guidance_sub_Obj"] = {file: "ert_main_cpp.html",line:20,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_cpp.html",line:34,type:"fcn"};
this.def["main"] = {file: "ert_main_cpp.html",line:71,type:"fcn"};
this.def["step"] = {file: "guidance_sub_cpp.html",line:19,type:"fcn"};
this.def["initialize"] = {file: "guidance_sub_cpp.html",line:128,type:"fcn"};
this.def["terminate"] = {file: "guidance_sub_cpp.html",line:160,type:"fcn"};
this.def["getRTM"] = {file: "guidance_sub_cpp.html",line:177,type:"fcn"};
this.def["DW_guidance_sub_T"] = {file: "guidance_sub_h.html",line:41,type:"type"};
this.def["ExtU_guidance_sub_T"] = {file: "guidance_sub_h.html",line:49,type:"type"};
this.def["ExtY_guidance_sub_T"] = {file: "guidance_sub_h.html",line:54,type:"type"};
this.def["guidance_sub_U"] = {file: "guidance_sub_h.html",line:77,type:"var"};
this.def["RT_MODEL_guidance_sub_T"] = {file: "guidance_sub_types_h.html",line:19,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:47,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:48,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:49,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:80,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:85,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:90,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:97,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:104,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:111,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:118,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:125,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:132,type:"type"};
this.def["cint64_T"] = {file: "rtwtypes_h.html",line:139,type:"type"};
this.def["cuint64_T"] = {file: "rtwtypes_h.html",line:146,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:167,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "/";
var isPC = false;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_cpp.html"] = "../ert_main.cpp";
	this.html2Root["ert_main_cpp.html"] = "ert_main_cpp.html";
	this.html2SrcPath["guidance_sub_cpp.html"] = "../guidance_sub.cpp";
	this.html2Root["guidance_sub_cpp.html"] = "guidance_sub_cpp.html";
	this.html2SrcPath["guidance_sub_h.html"] = "../guidance_sub.h";
	this.html2Root["guidance_sub_h.html"] = "guidance_sub_h.html";
	this.html2SrcPath["guidance_sub_private_h.html"] = "../guidance_sub_private.h";
	this.html2Root["guidance_sub_private_h.html"] = "guidance_sub_private_h.html";
	this.html2SrcPath["guidance_sub_types_h.html"] = "../guidance_sub_types.h";
	this.html2Root["guidance_sub_types_h.html"] = "guidance_sub_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_cpp.html","guidance_sub_cpp.html","guidance_sub_h.html","guidance_sub_private_h.html","guidance_sub_types_h.html","rtwtypes_h.html"];
