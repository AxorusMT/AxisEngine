# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=release
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),release)
  AxisEngine_config = release

else ifeq ($(config),debug)
  AxisEngine_config = debug

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := AxisEngine

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

AxisEngine:
ifneq (,$(AxisEngine_config))
	@echo "==== Building AxisEngine ($(AxisEngine_config)) ===="
	@${MAKE} --no-print-directory -C . -f AxisEngine.make config=$(AxisEngine_config)
endif

clean:
	@${MAKE} --no-print-directory -C . -f AxisEngine.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  release"
	@echo "  debug"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   AxisEngine"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"