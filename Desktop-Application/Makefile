TARGET = main
TARGET_PATH = ./APP

TARGET_TEST = tests
TARGET_TEST_PATH = ./test

INCLUDES = -I$(TARGET_PATH)/include -I$(TARGET_TEST_PATH)/include
CXXFLAGS = -std=c++17 -O2 -Wall $(INCLUDES)
LDFLAGS = -lm



HEADS_MAIN = $(shell find $(TARGET_PATH)/include -type f -name *.h)
SRCS_JUST_MAIN_NO__START  = $(shell find $(TARGET_PATH)/src -type f -name *.cpp ! -name $(TARGET).cpp)
OBJS_JUST_MAIN_NO__START = $(SRCS_JUST_MAIN_NO__START:.cpp=.o)
SRCS_JUST_MAIN__START  = $(SRCS_JUST_MAIN_NO__START) $(TARGET_PATH)/src/$(TARGET).cpp
OBJS_JUST_MAIN__START = $(SRCS_JUST_MAIN__START:.cpp=.o)

HEADS_TEST = $(shell find $(TARGET_TEST_PATH)/include -type f -name *.h)
SRCS_JUST_TEST_NO__START = $(shell find $(TARGET_TEST_PATH)/src  -type f -name *.cpp ! -name $(TARGET_TEST).cpp)
OBJS_JUST_TEST_NO__START = $(SRCS_JUST_TEST_NO__START:.cpp=.o)
SRCS_JUST_TEST__START = $(SRCS_JUST_TEST_NO__START) $(TARGET_TEST_PATH)/src/$(TARGET_TEST).cpp
OBJS_JUST_TEST__START = $(SRCS_JUST_TEST__START:.cpp=.o)

OBJS_ALL = $(OBJS_JUST_TEST__START) $(OBJS_JUST_MAIN__START)
SRCS_ALL = $(SRCS_JUST_MAIN__START) $(SRCS_JUST_TEST__START)
DEPS = Makefile.depend

OBJS_BUILD_MAIN = $(OBJS_JUST_MAIN__START)
OBJS_BUILD_TEST = $(OBJS_JUST_MAIN_NO__START) $(OBJS_JUST_TEST__START)
OBJS_BUILD_TESTS_NO_START = $(OBJS_JUST_MAIN_NO__START) $(OBJS_JUST_TEST_NO__START)

$(info -----------------MAIN--------------------)
$(info    HEADS_MAIN is $(HEADS_MAIN))
$(info    SRCS_JUST_MAIN_NO__START is $(SRCS_JUST_MAIN_NO__START))
$(info    OBJS_JUST_MAIN_NO__START is $(OBJS_JUST_MAIN_NO__START))
$(info    SRCS_JUST_MAIN__START is $(SRCS_JUST_MAIN__START))
$(info    OBJS_JUST_MAIN__START is $(OBJS_JUST_MAIN__START))
$(info -----------------TEST--------------------)
$(info    HEADS_TEST is $(HEADS_TEST))
$(info    SRCS_JUST_TEST_NO__START is $(SRCS_JUST_TEST_NO__START))
$(info    OBJS_JUST_TEST_NO__START is $(OBJS_JUST_TEST_NO__START))
$(info    SRCS_JUST_TEST__START is $(SRCS_JUST_TEST__START))
$(info    OBJS_JUST_TEST__START is $(OBJS_JUST_TEST__START))
$(info -----------------ALL---------------------)
$(info    OBJS_ALL is $(OBJS_ALL))
$(info    SRCS_ALL is $(SRCS_ALL))
$(info ----------------BUILD--------------------)
$(info    OBJS_BUILD_MAIN is $(OBJS_BUILD_MAIN))
$(info    OBJS_BUILD_TEST is $(OBJS_BUILD_TEST))
$(info    OBJS_BUILD_TESTS_NO_START is $(OBJS_BUILD_TESTS_NO_START))
$(info -----------------END---------------------)




all: $(TARGET)
	$(info -----------------all---------------------)

$(TARGET): $(OBJS_BUILD_MAIN) $(HEADS_MAIN)
	$(info ----------------TARGET-------------------)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS_BUILD_MAIN) -l sqlite3 -l ncurses

$(TARGET_TEST): $(OBJS_BUILD_TEST) $(HEADS_TEST)
	$(info --------------TARGET_TEST----------------)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS_BUILD_TEST) -l sqlite3 -l ncurses

$(TARGET_TEST_NO__START): $(OBJS_BUILD_TESTS_NO_START) $(HEADS_TEST)
	$(info ---------TARGET_TEST_NO__START-----------)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS_BUILD_TESTS_NO_START) -l sqlite3 -l ncurses

run: all
	$(info -----------------run---------------------)
	@./$(TARGET)

run_test: $(TARGET_TEST)
	$(info ---------------run_test------------------)
	@./$(TARGET_TEST)

.PHONY: depend clean
depend:
	$(info ----------------depend-------------------)
	$(CXX) $(INCLUDES) -MM $(SRCS_ALL) > $(DEPS)
	@sed -i -E "s/^(.+?).o: ([^ ]+?)\1/\2\1.o: \2\1/g" $(DEPS)

clean:
	$(info ---------------clean-------------------)
	$(RM) $(OBJS_ALL) $(OBJS_ALL:.o=.o.exe) $(TARGET) $(TARGET_TEST) *.db

-include $(DEPS)


run_all_tests: clean $(OBJS_BUILD_TESTS_NO_START)  $(TARGET_TEST_NO__START)
	$(info --------------run_all_tests---------------)
	for i in $(OBJS_JUST_TEST_NO__START) ; do \
      		$(CXX) $(LDFLAGS) -o $$i.exe  $(OBJS_JUST_MAIN_NO__START) $$i -l sqlite3 -l ncurses  ;\
      		export P0=$$(echo $${i}| cut -d '/' -f 2); \
      		export P1=$$(echo $${i}| cut -d '/' -f 3); \
      		export P2=$$(echo $${i}| cut -d '/' -f 4); \
      		export SubPath=$$(echo ./$${P0}/$${P1}/$${P2}); \
      		chmod +x $$i.exe;\
      		echo "TEST::"$$P2;\
      		touch $${SubPath}/in ;\
      		touch $${SubPath}/out ;\
      		touch $${SubPath}/out.correct ;\
      		$$i.exe <  $${SubPath}/in > $${SubPath}/out || exit 1 ;\
      		diff $${SubPath}/out $${SubPath}/out.correct || exit 1 ;\
      		echo "TEST::PASSED" && echo;\
        done
