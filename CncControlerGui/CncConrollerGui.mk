##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=CncConrollerGui
ConfigurationName      :=Release
WorkspacePath          :=C:/@Development/@Projekte/@c++/CnCControl
ProjectPath            :=C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hoelste
Date                   :=23/03/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)APP_USE_SPLASH $(PreprocessorSwitch)USE_WXCRAFTER 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CncConrollerGui.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/windres.exe
LinkOptions            :=  $(shell wx-config --libs) -mwindows
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)wxmsw31u_stc $(LibrarySwitch)wxmsw31u_webview $(LibrarySwitch)wxmsw31u_propgrid $(LibrarySwitch)wxmsw31u_adv $(LibrarySwitch)wxmsw31u_gl $(LibrarySwitch)opengl32 $(LibrarySwitch)glu32 
ArLibs                 :=  "libwxmsw31u_stc" "libwxmsw31u_webview" "libwxmsw31u_propgrid" "libwxmsw31u_adv" "libwxmsw31u_gl" "opengl32" "glu32" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/ar.exe rcu
CXX      := C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/g++.exe
CC       := C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/gcc.exe
CXXFLAGS := -Wno-deprecated-declarations -O2 -std=c++14 -std=c++11 -Wall $(shell wx-config --cflags) $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/@Development/mingw-w64/i686-6.2.0-posix-dwarf-rt_v5-rev1/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
WXWIN:=C:\@Development\wxWidgets-3.1.0
WXCFG:=gcc_dll\mswu
Objects0=$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(IntermediateDirectory)/GCodeFileParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/GCodeCommands.cpp$(ObjectSuffix) $(IntermediateDirectory)/GCodeBlock.cpp$(ObjectSuffix) $(IntermediateDirectory)/GCodeField.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncDrawPane.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncDrawPaneContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/trackball.cpp$(ObjectSuffix) $(IntermediateDirectory)/EndSwitchDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/PathGeneratorFrame.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/SerialEmulatorFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/SerialEmulatorNull.cpp$(ObjectSuffix) $(IntermediateDirectory)/SerialEmulatorSVG.cpp$(ObjectSuffix) $(IntermediateDirectory)/SerialPort.cpp$(ObjectSuffix) $(IntermediateDirectory)/SVGCurveLib.cpp$(ObjectSuffix) $(IntermediateDirectory)/SvgEditPopup.cpp$(ObjectSuffix) $(IntermediateDirectory)/SVGFileParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/SVGPathHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/SvgUnitCalculator.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncArduino.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/CncControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncControllerTestSuite.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncFileNameService.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncPathReverser.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncSvgCurveLib.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncToolCorrection.cpp$(ObjectSuffix) $(IntermediateDirectory)/CncToolStateControl.cpp$(ObjectSuffix) $(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/InterruptThread.cpp$(ObjectSuffix) $(IntermediateDirectory)/DataControlModel.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/GCodeFileParser.cpp$(ObjectSuffix): GCodeFileParser.cpp $(IntermediateDirectory)/GCodeFileParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/GCodeFileParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GCodeFileParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GCodeFileParser.cpp$(DependSuffix): GCodeFileParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GCodeFileParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GCodeFileParser.cpp$(DependSuffix) -MM GCodeFileParser.cpp

$(IntermediateDirectory)/GCodeFileParser.cpp$(PreprocessSuffix): GCodeFileParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GCodeFileParser.cpp$(PreprocessSuffix) GCodeFileParser.cpp

$(IntermediateDirectory)/GCodeCommands.cpp$(ObjectSuffix): GCodeCommands.cpp $(IntermediateDirectory)/GCodeCommands.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/GCodeCommands.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GCodeCommands.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GCodeCommands.cpp$(DependSuffix): GCodeCommands.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GCodeCommands.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GCodeCommands.cpp$(DependSuffix) -MM GCodeCommands.cpp

$(IntermediateDirectory)/GCodeCommands.cpp$(PreprocessSuffix): GCodeCommands.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GCodeCommands.cpp$(PreprocessSuffix) GCodeCommands.cpp

$(IntermediateDirectory)/GCodeBlock.cpp$(ObjectSuffix): GCodeBlock.cpp $(IntermediateDirectory)/GCodeBlock.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/GCodeBlock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GCodeBlock.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GCodeBlock.cpp$(DependSuffix): GCodeBlock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GCodeBlock.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GCodeBlock.cpp$(DependSuffix) -MM GCodeBlock.cpp

$(IntermediateDirectory)/GCodeBlock.cpp$(PreprocessSuffix): GCodeBlock.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GCodeBlock.cpp$(PreprocessSuffix) GCodeBlock.cpp

$(IntermediateDirectory)/GCodeField.cpp$(ObjectSuffix): GCodeField.cpp $(IntermediateDirectory)/GCodeField.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/GCodeField.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GCodeField.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GCodeField.cpp$(DependSuffix): GCodeField.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GCodeField.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GCodeField.cpp$(DependSuffix) -MM GCodeField.cpp

$(IntermediateDirectory)/GCodeField.cpp$(PreprocessSuffix): GCodeField.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GCodeField.cpp$(PreprocessSuffix) GCodeField.cpp

$(IntermediateDirectory)/CncDrawPane.cpp$(ObjectSuffix): CncDrawPane.cpp $(IntermediateDirectory)/CncDrawPane.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncDrawPane.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncDrawPane.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncDrawPane.cpp$(DependSuffix): CncDrawPane.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncDrawPane.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncDrawPane.cpp$(DependSuffix) -MM CncDrawPane.cpp

$(IntermediateDirectory)/CncDrawPane.cpp$(PreprocessSuffix): CncDrawPane.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncDrawPane.cpp$(PreprocessSuffix) CncDrawPane.cpp

$(IntermediateDirectory)/CncDrawPaneContext.cpp$(ObjectSuffix): CncDrawPaneContext.cpp $(IntermediateDirectory)/CncDrawPaneContext.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncDrawPaneContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncDrawPaneContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncDrawPaneContext.cpp$(DependSuffix): CncDrawPaneContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncDrawPaneContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncDrawPaneContext.cpp$(DependSuffix) -MM CncDrawPaneContext.cpp

$(IntermediateDirectory)/CncDrawPaneContext.cpp$(PreprocessSuffix): CncDrawPaneContext.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncDrawPaneContext.cpp$(PreprocessSuffix) CncDrawPaneContext.cpp

$(IntermediateDirectory)/trackball.cpp$(ObjectSuffix): trackball.cpp $(IntermediateDirectory)/trackball.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/trackball.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/trackball.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/trackball.cpp$(DependSuffix): trackball.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/trackball.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/trackball.cpp$(DependSuffix) -MM trackball.cpp

$(IntermediateDirectory)/trackball.cpp$(PreprocessSuffix): trackball.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/trackball.cpp$(PreprocessSuffix) trackball.cpp

$(IntermediateDirectory)/EndSwitchDialog.cpp$(ObjectSuffix): EndSwitchDialog.cpp $(IntermediateDirectory)/EndSwitchDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/EndSwitchDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/EndSwitchDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/EndSwitchDialog.cpp$(DependSuffix): EndSwitchDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/EndSwitchDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/EndSwitchDialog.cpp$(DependSuffix) -MM EndSwitchDialog.cpp

$(IntermediateDirectory)/EndSwitchDialog.cpp$(PreprocessSuffix): EndSwitchDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/EndSwitchDialog.cpp$(PreprocessSuffix) EndSwitchDialog.cpp

$(IntermediateDirectory)/PathGeneratorFrame.cpp$(ObjectSuffix): PathGeneratorFrame.cpp $(IntermediateDirectory)/PathGeneratorFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/PathGeneratorFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PathGeneratorFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PathGeneratorFrame.cpp$(DependSuffix): PathGeneratorFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PathGeneratorFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PathGeneratorFrame.cpp$(DependSuffix) -MM PathGeneratorFrame.cpp

$(IntermediateDirectory)/PathGeneratorFrame.cpp$(PreprocessSuffix): PathGeneratorFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PathGeneratorFrame.cpp$(PreprocessSuffix) PathGeneratorFrame.cpp

$(IntermediateDirectory)/SerialEmulatorFile.cpp$(ObjectSuffix): SerialEmulatorFile.cpp $(IntermediateDirectory)/SerialEmulatorFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SerialEmulatorFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SerialEmulatorFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SerialEmulatorFile.cpp$(DependSuffix): SerialEmulatorFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SerialEmulatorFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SerialEmulatorFile.cpp$(DependSuffix) -MM SerialEmulatorFile.cpp

$(IntermediateDirectory)/SerialEmulatorFile.cpp$(PreprocessSuffix): SerialEmulatorFile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SerialEmulatorFile.cpp$(PreprocessSuffix) SerialEmulatorFile.cpp

$(IntermediateDirectory)/SerialEmulatorNull.cpp$(ObjectSuffix): SerialEmulatorNull.cpp $(IntermediateDirectory)/SerialEmulatorNull.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SerialEmulatorNull.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SerialEmulatorNull.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SerialEmulatorNull.cpp$(DependSuffix): SerialEmulatorNull.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SerialEmulatorNull.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SerialEmulatorNull.cpp$(DependSuffix) -MM SerialEmulatorNull.cpp

$(IntermediateDirectory)/SerialEmulatorNull.cpp$(PreprocessSuffix): SerialEmulatorNull.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SerialEmulatorNull.cpp$(PreprocessSuffix) SerialEmulatorNull.cpp

$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(ObjectSuffix): SerialEmulatorSVG.cpp $(IntermediateDirectory)/SerialEmulatorSVG.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SerialEmulatorSVG.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(DependSuffix): SerialEmulatorSVG.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(DependSuffix) -MM SerialEmulatorSVG.cpp

$(IntermediateDirectory)/SerialEmulatorSVG.cpp$(PreprocessSuffix): SerialEmulatorSVG.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SerialEmulatorSVG.cpp$(PreprocessSuffix) SerialEmulatorSVG.cpp

$(IntermediateDirectory)/SerialPort.cpp$(ObjectSuffix): SerialPort.cpp $(IntermediateDirectory)/SerialPort.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SerialPort.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SerialPort.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SerialPort.cpp$(DependSuffix): SerialPort.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SerialPort.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SerialPort.cpp$(DependSuffix) -MM SerialPort.cpp

$(IntermediateDirectory)/SerialPort.cpp$(PreprocessSuffix): SerialPort.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SerialPort.cpp$(PreprocessSuffix) SerialPort.cpp

$(IntermediateDirectory)/SVGCurveLib.cpp$(ObjectSuffix): SVGCurveLib.cpp $(IntermediateDirectory)/SVGCurveLib.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SVGCurveLib.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SVGCurveLib.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SVGCurveLib.cpp$(DependSuffix): SVGCurveLib.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SVGCurveLib.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SVGCurveLib.cpp$(DependSuffix) -MM SVGCurveLib.cpp

$(IntermediateDirectory)/SVGCurveLib.cpp$(PreprocessSuffix): SVGCurveLib.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SVGCurveLib.cpp$(PreprocessSuffix) SVGCurveLib.cpp

$(IntermediateDirectory)/SvgEditPopup.cpp$(ObjectSuffix): SvgEditPopup.cpp $(IntermediateDirectory)/SvgEditPopup.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SvgEditPopup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SvgEditPopup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SvgEditPopup.cpp$(DependSuffix): SvgEditPopup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SvgEditPopup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SvgEditPopup.cpp$(DependSuffix) -MM SvgEditPopup.cpp

$(IntermediateDirectory)/SvgEditPopup.cpp$(PreprocessSuffix): SvgEditPopup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SvgEditPopup.cpp$(PreprocessSuffix) SvgEditPopup.cpp

$(IntermediateDirectory)/SVGFileParser.cpp$(ObjectSuffix): SVGFileParser.cpp $(IntermediateDirectory)/SVGFileParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SVGFileParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SVGFileParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SVGFileParser.cpp$(DependSuffix): SVGFileParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SVGFileParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SVGFileParser.cpp$(DependSuffix) -MM SVGFileParser.cpp

$(IntermediateDirectory)/SVGFileParser.cpp$(PreprocessSuffix): SVGFileParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SVGFileParser.cpp$(PreprocessSuffix) SVGFileParser.cpp

$(IntermediateDirectory)/SVGPathHandler.cpp$(ObjectSuffix): SVGPathHandler.cpp $(IntermediateDirectory)/SVGPathHandler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SVGPathHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SVGPathHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SVGPathHandler.cpp$(DependSuffix): SVGPathHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SVGPathHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SVGPathHandler.cpp$(DependSuffix) -MM SVGPathHandler.cpp

$(IntermediateDirectory)/SVGPathHandler.cpp$(PreprocessSuffix): SVGPathHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SVGPathHandler.cpp$(PreprocessSuffix) SVGPathHandler.cpp

$(IntermediateDirectory)/SvgUnitCalculator.cpp$(ObjectSuffix): SvgUnitCalculator.cpp $(IntermediateDirectory)/SvgUnitCalculator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/SvgUnitCalculator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SvgUnitCalculator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SvgUnitCalculator.cpp$(DependSuffix): SvgUnitCalculator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SvgUnitCalculator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SvgUnitCalculator.cpp$(DependSuffix) -MM SvgUnitCalculator.cpp

$(IntermediateDirectory)/SvgUnitCalculator.cpp$(PreprocessSuffix): SvgUnitCalculator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SvgUnitCalculator.cpp$(PreprocessSuffix) SvgUnitCalculator.cpp

$(IntermediateDirectory)/CncArduino.cpp$(ObjectSuffix): CncArduino.cpp $(IntermediateDirectory)/CncArduino.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncArduino.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncArduino.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncArduino.cpp$(DependSuffix): CncArduino.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncArduino.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncArduino.cpp$(DependSuffix) -MM CncArduino.cpp

$(IntermediateDirectory)/CncArduino.cpp$(PreprocessSuffix): CncArduino.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncArduino.cpp$(PreprocessSuffix) CncArduino.cpp

$(IntermediateDirectory)/CncControl.cpp$(ObjectSuffix): CncControl.cpp $(IntermediateDirectory)/CncControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncControl.cpp$(DependSuffix): CncControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncControl.cpp$(DependSuffix) -MM CncControl.cpp

$(IntermediateDirectory)/CncControl.cpp$(PreprocessSuffix): CncControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncControl.cpp$(PreprocessSuffix) CncControl.cpp

$(IntermediateDirectory)/CncControllerTestSuite.cpp$(ObjectSuffix): CncControllerTestSuite.cpp $(IntermediateDirectory)/CncControllerTestSuite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncControllerTestSuite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncControllerTestSuite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncControllerTestSuite.cpp$(DependSuffix): CncControllerTestSuite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncControllerTestSuite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncControllerTestSuite.cpp$(DependSuffix) -MM CncControllerTestSuite.cpp

$(IntermediateDirectory)/CncControllerTestSuite.cpp$(PreprocessSuffix): CncControllerTestSuite.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncControllerTestSuite.cpp$(PreprocessSuffix) CncControllerTestSuite.cpp

$(IntermediateDirectory)/CncFileNameService.cpp$(ObjectSuffix): CncFileNameService.cpp $(IntermediateDirectory)/CncFileNameService.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncFileNameService.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncFileNameService.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncFileNameService.cpp$(DependSuffix): CncFileNameService.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncFileNameService.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncFileNameService.cpp$(DependSuffix) -MM CncFileNameService.cpp

$(IntermediateDirectory)/CncFileNameService.cpp$(PreprocessSuffix): CncFileNameService.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncFileNameService.cpp$(PreprocessSuffix) CncFileNameService.cpp

$(IntermediateDirectory)/CncPathReverser.cpp$(ObjectSuffix): CncPathReverser.cpp $(IntermediateDirectory)/CncPathReverser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncPathReverser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncPathReverser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncPathReverser.cpp$(DependSuffix): CncPathReverser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncPathReverser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncPathReverser.cpp$(DependSuffix) -MM CncPathReverser.cpp

$(IntermediateDirectory)/CncPathReverser.cpp$(PreprocessSuffix): CncPathReverser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncPathReverser.cpp$(PreprocessSuffix) CncPathReverser.cpp

$(IntermediateDirectory)/CncSvgCurveLib.cpp$(ObjectSuffix): CncSvgCurveLib.cpp $(IntermediateDirectory)/CncSvgCurveLib.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncSvgCurveLib.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncSvgCurveLib.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncSvgCurveLib.cpp$(DependSuffix): CncSvgCurveLib.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncSvgCurveLib.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncSvgCurveLib.cpp$(DependSuffix) -MM CncSvgCurveLib.cpp

$(IntermediateDirectory)/CncSvgCurveLib.cpp$(PreprocessSuffix): CncSvgCurveLib.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncSvgCurveLib.cpp$(PreprocessSuffix) CncSvgCurveLib.cpp

$(IntermediateDirectory)/CncToolCorrection.cpp$(ObjectSuffix): CncToolCorrection.cpp $(IntermediateDirectory)/CncToolCorrection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncToolCorrection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncToolCorrection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncToolCorrection.cpp$(DependSuffix): CncToolCorrection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncToolCorrection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncToolCorrection.cpp$(DependSuffix) -MM CncToolCorrection.cpp

$(IntermediateDirectory)/CncToolCorrection.cpp$(PreprocessSuffix): CncToolCorrection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncToolCorrection.cpp$(PreprocessSuffix) CncToolCorrection.cpp

$(IntermediateDirectory)/CncToolStateControl.cpp$(ObjectSuffix): CncToolStateControl.cpp $(IntermediateDirectory)/CncToolStateControl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/CncToolStateControl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CncToolStateControl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CncToolStateControl.cpp$(DependSuffix): CncToolStateControl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CncToolStateControl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CncToolStateControl.cpp$(DependSuffix) -MM CncToolStateControl.cpp

$(IntermediateDirectory)/CncToolStateControl.cpp$(PreprocessSuffix): CncToolStateControl.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CncToolStateControl.cpp$(PreprocessSuffix) CncToolStateControl.cpp

$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(ObjectSuffix): Codelite/wxPNGAnimation.cpp $(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/Codelite/wxPNGAnimation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(DependSuffix): Codelite/wxPNGAnimation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(DependSuffix) -MM Codelite/wxPNGAnimation.cpp

$(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(PreprocessSuffix): Codelite/wxPNGAnimation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Codelite_wxPNGAnimation.cpp$(PreprocessSuffix) Codelite/wxPNGAnimation.cpp

$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix): wxcrafter.cpp $(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/wxcrafter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix): wxcrafter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter.cpp$(DependSuffix) -MM wxcrafter.cpp

$(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix): wxcrafter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter.cpp$(PreprocessSuffix) wxcrafter.cpp

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix): wxcrafter_bitmaps.cpp $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/wxcrafter_bitmaps.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix): wxcrafter_bitmaps.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(DependSuffix) -MM wxcrafter_bitmaps.cpp

$(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix): wxcrafter_bitmaps.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxcrafter_bitmaps.cpp$(PreprocessSuffix) wxcrafter_bitmaps.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix): MainFrame.cpp $(IntermediateDirectory)/MainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/MainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix): MainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainFrame.cpp$(DependSuffix) -MM MainFrame.cpp

$(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix): MainFrame.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainFrame.cpp$(PreprocessSuffix) MainFrame.cpp

$(IntermediateDirectory)/InterruptThread.cpp$(ObjectSuffix): InterruptThread.cpp $(IntermediateDirectory)/InterruptThread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/InterruptThread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InterruptThread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InterruptThread.cpp$(DependSuffix): InterruptThread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InterruptThread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InterruptThread.cpp$(DependSuffix) -MM InterruptThread.cpp

$(IntermediateDirectory)/InterruptThread.cpp$(PreprocessSuffix): InterruptThread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InterruptThread.cpp$(PreprocessSuffix) InterruptThread.cpp

$(IntermediateDirectory)/DataControlModel.cpp$(ObjectSuffix): DataControlModel.cpp $(IntermediateDirectory)/DataControlModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/@Development/@Projekte/@c++/CnCControl/CncControlerGui/DataControlModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DataControlModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DataControlModel.cpp$(DependSuffix): DataControlModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DataControlModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DataControlModel.cpp$(DependSuffix) -MM DataControlModel.cpp

$(IntermediateDirectory)/DataControlModel.cpp$(PreprocessSuffix): DataControlModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DataControlModel.cpp$(PreprocessSuffix) DataControlModel.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


