################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJ = motEncPot

-include "..\makefile.init"

all:

clean:
	@rm -f $(GENERATED_FILES)

-include "subdir.mk"
-include "..\makefile.defs"

PCP_FILES :=
EXT_LIBRARIES =

all : "motEncPot.elf"

"motEncPot.elf" : $(OBJ_FILES) $(EXT_LIBRARIES) ".motEncPot.elf.opt"
	@echo Linking to ${@F}
	@"C:\Program Files\DEVEL\TriCore v3.5r1\ctc\bin\cctc" -f ".motEncPot.elf.opt"

".motEncPot.elf.opt" : .refresh
	@argfile ".motEncPot.elf.opt" -o "motEncPot.elf" $(OBJ_FILES) $(EXT_LIBRARIES) $(PCP_FILES) -C"TC1782" -t "../${PROJ}.lsl" -Wl-OtxycL --no-map-file -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g -Wl--dep-file=".motEncPot.elf.d" -Wl--make-target="motEncPot.elf"
DEPENDENCY_FILES += ".motEncPot.elf.d"
-include $(DEPENDENCY_FILES)

GENERATED_FILES += "motEncPot.elf" "motEncPot.mapxml" "motEncPot.mdf" ".motEncPot.elf.opt" "console.log"
-include "..\makefile.targets"

.PHONY : .refresh
