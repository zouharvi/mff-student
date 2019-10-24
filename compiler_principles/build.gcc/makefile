# build everything from public-cpp and private-src

PUBLIC_CPP_NAMES = \
	gen_aifactory \
	gen_icfactory \
	gen_icinstrtab \
	abstract_ic \
	flat_icblock \
	ic_instr \
	labeled_icblock \
	uid_gen \
	gen_instr_decode \
	gen_machines \
	gen_mops \
	icexcept \
	icm_machine \
	duerr \
	dusememptyerrtab \
	dutables

PUBLIC_CPP_NAMES12 = \
	dummyg \
	du12

PUBLIC_CPP_NAMES3 = \
	du3

PUBLIC_CPP_NAMES4 = \
	du4

PUBLIC_CPP_NAMES56 = \
	du56

PUBLIC_HEADER_FILES = \
	gen_ainstr.hpp \
	gen_icinstr.hpp \
	gen_icopcodes.hpp \
	abstract_ic.hpp \
	el_shr_ptr.hpp \
	ic_factory.hpp \
	ic_opcodes.hpp \
	plain_icblock.hpp \
	abstract_instr.hpp \
	carray.hpp \
	file_seq.hpp \
	ic_instr.hpp \
	labeled_icblock.hpp \
	uid_gen.hpp \
	ai_factory.hpp \
	common_types.hpp \
	flat_icblock.hpp \
	ic_instrtab.hpp \
	literal_storage.hpp \
	gen_mopcodes.hpp \
	icexcept.hpp \
	icm_flat_icblock.hpp \
	icm_machine.hpp \
	icm_types.hpp \
	icm_val.hpp \
	mops.hpp \
	bisonflex.hpp \
	dubaseerr.hpp \
	duerr.hpp \
	dutables.hpp \
	dummyg.hpp
	
PRIVATE_FLEX_NAMES12 = \
	du12l
	
PRIVATE_FLEX_NAMES3456 = \
	du3456l
	
PRIVATE_BISON_NAMES3456 = \
	du3456g
	
PRIVATE_CPP_NAMES12 = \
	du12sem
	
PRIVATE_CPP_NAMES3456 = \
	du3456sem
	
PRIVATE_HEADER_FILES = \
	du12sem.hpp \
	du3456sem.hpp

PUBLIC_FOLDER = ../public-cpp

PRIVATE_FOLDER = ../private-src

TEMP_FOLDER = tmp

TARGET_NAME12 = du12

TARGET_NAME3 = du3

TARGET_NAME4 = du4

TARGET_NAME56 = du56

#############################################################################

TEST_NAMES1 = \
	du1-test1 \
	du1-test2
	
TEST_NAMES2 = \
	du2-test1 \
	du2-test2 \
	du2-test3 
	
TEST_NAMES3 = \
	du3-test1a \
	du3-test21 \
	du3-test22 \
	du3-test23 \
	du3-test24 \
	du3-test25a \
	du3-test26a \
	du3-test27 \
	du3-test28a \
	du3-test29 \
	du3-test2a \
	du3-test30a \
	du3-test41r \
	du3-test44r

TEST_NAMES4 = \
	du4-test1a \
	du4-test2 \
	du4-test3a \
	du4-test41r \
	du4-test44r \
	du4-test4 \
	du4-test51a \
	du4-test52a \
	du4-test53a \
	du4-test54 \
	du4-test55 \
	du4-test56a \
	du4-test5a \
	du4-test6r \
	du4-test9c

TEST_NAMES5 = \
	du5-test1 \
	du5-test2a \
	du5-test31 \
	du5-test3c \
	du5-test4r

TEST_NAMES6 = \
	du6-test10 \
	du6-test12 \
	du6-test13 \
	du6-test14 \
	du6-test1a \
	du6-test1r \
	du6-test20a \
	du6-test20r \
	du6-test21a \
	du6-test21r \
	du6-test22a \
	du6-test22r \
	du6-test23a \
	du6-test23r \
	du6-test30 \
	du6-test33 \
	du6-test34 \
	du6-test3 \
	du6-test4 \
	du6-test5 \
	du6-test6 \
	du6-test7 \
	du6-test8 \
	du6-test9 \
	du6-test11n \
	du6-test2n \
	du6-test32n

TEST_FOLDER = ../public-tests

#############################################################################

TEMP_FOLDER_FILE = $(TEMP_FOLDER)/here.iam

GENERATED_CPP_NAMES12 = $(PRIVATE_FLEX_NAMES12) 

GENERATED_CPP_NAMES3456 = $(PRIVATE_FLEX_NAMES3456) $(PRIVATE_BISON_NAMES3456)

LINKED_NAMES12 = $(PUBLIC_CPP_NAMES) $(PUBLIC_CPP_NAMES12) $(PRIVATE_CPP_NAMES12) $(GENERATED_CPP_NAMES12)

LINKED_NAMES3 = $(PUBLIC_CPP_NAMES) $(PUBLIC_CPP_NAMES3) $(PRIVATE_CPP_NAMES3456) $(GENERATED_CPP_NAMES3456)

LINKED_NAMES4 = $(PUBLIC_CPP_NAMES) $(PUBLIC_CPP_NAMES4) $(PRIVATE_CPP_NAMES3456) $(GENERATED_CPP_NAMES3456)

LINKED_NAMES56 = $(PUBLIC_CPP_NAMES) $(PUBLIC_CPP_NAMES56) $(PRIVATE_CPP_NAMES3456) $(GENERATED_CPP_NAMES3456)

LINKED_NAMES = $(PUBLIC_CPP_NAMES) $(PUBLIC_CPP_NAMES12) $(PUBLIC_CPP_NAMES3) $(PUBLIC_CPP_NAMES4) $(PUBLIC_CPP_NAMES56) $(PRIVATE_CPP_NAMES12) $(PRIVATE_CPP_NAMES3456) $(GENERATED_CPP_NAMES12) $(GENERATED_CPP_NAMES3456)

LINKED_OBJS12 = $(LINKED_NAMES12:%=$(TEMP_FOLDER)/%.o)

LINKED_OBJS3 = $(LINKED_NAMES3:%=$(TEMP_FOLDER)/%.o)

LINKED_OBJS4 = $(LINKED_NAMES4:%=$(TEMP_FOLDER)/%.o)

LINKED_OBJS56 = $(LINKED_NAMES56:%=$(TEMP_FOLDER)/%.o)

LINKED_OBJS = $(LINKED_NAMES:%=$(TEMP_FOLDER)/%.o)

TARGET_FILE12 = $(TEMP_FOLDER)/$(TARGET_NAME12)

TARGET_FILE3 = $(TEMP_FOLDER)/$(TARGET_NAME3)

TARGET_FILE4 = $(TEMP_FOLDER)/$(TARGET_NAME4)

TARGET_FILE56 = $(TEMP_FOLDER)/$(TARGET_NAME56)

GENERATED_HEADER_FILES = stack.hh $(PRIVATE_BISON_NAMES3456:%=%.hpp) 

GENERATED_FILES = $(GENERATED_CPP_NAMES12:%=%.cpp) $(GENERATED_CPP_NAMES3456:%=%.cpp) $(GENERATED_HEADER_FILES)

BYPRODUCT_FILES = lex.backup $(PRIVATE_BISON_NAMES3456:%=%.output)

TEMPORARY_FILES = $(BYPRODUCT_FILES) $(GENERATED_FILES) $(LINKED_OBJS) $(TARGET_FILE12) $(TARGET_FILE3) $(TARGET_FILE4) $(TARGET_FILE56)

INCLUDED_HEADER_FILES = $(PUBLIC_HEADER_FILES) $(PRIVATE_HEADER_FILES) $(GENERATED_HEADER_FILES)

INCLUDE_OPTS = \
	-I$(PUBLIC_FOLDER) \
	-I$(PRIVATE_FOLDER) \
	-I.

FLEX_COMMAND = flex -Cf -b -p -p -o$*.cpp $<

BISON_COMMAND = bison --report=all -d -o$*.cpp $<

COMPILE_COMMAND = g++ -c -std=c++17 $(INCLUDE_OPTS) -o$@ $<

LINK_COMMAND = g++ -o$@ $^

#############################################################################

OUT_FILES1 = $(TEST_NAMES1:%=%.out)

OUT_FILES2 = $(TEST_NAMES2:%=%.out)

OUT_FILES3 = $(TEST_NAMES3:%=%.out)

OUT_FILES4 = $(TEST_NAMES4:%=%.out)

OUT_FILES5 = $(TEST_NAMES5:%=%.out)

OUT_FILES6 = $(TEST_NAMES6:%=%.out)

OUT_FILES = $(OUT_FILES1) $(OUT_FILES2) $(OUT_FILES3) $(OUT_FILES4) $(OUT_FILES5) $(OUT_FILES6) 

#############################################################################

VPATH = \
	$(PUBLIC_FOLDER) \
	$(PRIVATE_FOLDER)

all: $(TEMP_FOLDER_FILE) du12 du3 du4 du56

.PHONY: du12 du3 du4 du56 du1 du2 du5 du6

du12: $(TARGET_FILE12)

du3: $(TARGET_FILE3)

du4: $(TARGET_FILE4)

du56: $(TARGET_FILE56)

du1: $(TARGET_FILE12)

du2: $(TARGET_FILE12)

du5: $(TARGET_FILE56)

du6: $(TARGET_FILE56)

.PHONY: test1 test2 test3 test4 test5 test6

test1: $(OUT_FILES1)

test2: $(OUT_FILES2)

test3: $(OUT_FILES3)

test4: $(OUT_FILES4)

test5: $(OUT_FILES5)

test6: $(OUT_FILES6)

.PHONY: clean
clean:
	rm $(TEMPORARY_FILES) $(OUT_FILES)

.SECONDARY: $(TEMPORARY_FILES)

$(TEMP_FOLDER_FILE):
	mkdir -p $(TEMP_FOLDER)
	touch $@

$(TARGET_FILE12): $(LINKED_OBJS12)
	$(LINK_COMMAND)

$(TARGET_FILE3): $(LINKED_OBJS3)
	$(LINK_COMMAND)

$(TARGET_FILE4): $(LINKED_OBJS4)
	$(LINK_COMMAND)

$(TARGET_FILE56): $(LINKED_OBJS56)
	$(LINK_COMMAND)

$(TEMP_FOLDER)/%.o: %.cpp $(INCLUDED_HEADER_FILES)
	$(COMPILE_COMMAND)

%.cpp %.hpp: %.y
	$(BISON_COMMAND)

stack.hh: $(PRIVATE_BISON_NAMES3456:%=%.hpp)

%.cpp: %.lex
	$(FLEX_COMMAND)

##################################################################################

du1-test%.out: $(TEST_FOLDER)/du1-test%.mls $(TARGET_FILE12)
	$(TARGET_FILE12) $< > $@

du2-test%.out: $(TEST_FOLDER)/du2-test%.mls $(TARGET_FILE12)
	$(TARGET_FILE12) $< > $@

du3-test%.out: $(TEST_FOLDER)/du3-test%.mls $(TARGET_FILE3)
	$(TARGET_FILE3) $< > $@

du4-test%.out: $(TEST_FOLDER)/du4-test%.mls $(TARGET_FILE4)
	$(TARGET_FILE4) $< > $@

du5-test%.out: $(TEST_FOLDER)/du5-test%.mls $(TARGET_FILE56)
	$(TARGET_FILE56) $< > $@

du6-test%.out: $(TEST_FOLDER)/du6-test%.mls $(TARGET_FILE56)
	$(TARGET_FILE56) $< > $@

##################################################################################
