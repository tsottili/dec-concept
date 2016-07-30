##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=dec-concept
ConfigurationName      :=Debug
WorkspacePath          := "/home/toms/Progetti/codelite/github/dec-concept"
ProjectPath            := "/home/toms/Progetti/codelite/github/dec-concept/dec-concept"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=toms
Date                   :=30/07/16
CodeLitePath           :="/home/toms/.codelite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="dec-concept.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/llvm-ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_consumer.cpp$(ObjectSuffix) $(IntermediateDirectory)/event_dispatcher.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/toms/Progetti/codelite/github/dec-concept/dec-concept/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/event_consumer.cpp$(ObjectSuffix): event_consumer.cpp $(IntermediateDirectory)/event_consumer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/toms/Progetti/codelite/github/dec-concept/dec-concept/event_consumer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_consumer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_consumer.cpp$(DependSuffix): event_consumer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_consumer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_consumer.cpp$(DependSuffix) -MM "event_consumer.cpp"

$(IntermediateDirectory)/event_consumer.cpp$(PreprocessSuffix): event_consumer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_consumer.cpp$(PreprocessSuffix) "event_consumer.cpp"

$(IntermediateDirectory)/event_dispatcher.cpp$(ObjectSuffix): event_dispatcher.cpp $(IntermediateDirectory)/event_dispatcher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/toms/Progetti/codelite/github/dec-concept/dec-concept/event_dispatcher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event_dispatcher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event_dispatcher.cpp$(DependSuffix): event_dispatcher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event_dispatcher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/event_dispatcher.cpp$(DependSuffix) -MM "event_dispatcher.cpp"

$(IntermediateDirectory)/event_dispatcher.cpp$(PreprocessSuffix): event_dispatcher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event_dispatcher.cpp$(PreprocessSuffix) "event_dispatcher.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


