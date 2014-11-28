##############################################
#
# Makefile pour le projet PatternTown
# Auteurs : Thomas Chevrel, Theo Delalande
#
##############################################



##############################################
# Informations de compilation
EXEC=PatternTown
CXXFLAGS=-std=c++0x



##############################################
# Dossiers
SRCDIR=src src/batiments src/village src/village/etats src/villageois src/villageois/decorations
OBJDIR=obj



##############################################
# Fichiers
SOURCES=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp))
OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCES)))
vpath %.cpp $(SRCDIR)



##############################################
# Compilation complète

gcc: clean
gcc: CXX=g++
gcc: LINKER=g++ -o
gcc: CXXFLAGS += -DNDEBUG
gcc: $(EXEC)

gcc-debug: clean
gcc-debug: CXX=g++
gcc-debug: LINKER=g++ -o
gcc-debug: CXXFLAGS += -g
gcc-debug: $(EXEC)


$(EXEC): $(OBJECTS)
	@$(LINKER) $@ $^

$(OBJDIR)/%.o: %.cpp

	@$(CXX) $(CXXFLAGS) -c $< -o $@


	
##############################################
# Règles PHONY

.PHONY: gcc gcc-debug begin clean doc



##############################################
# Création des repertoires

begin:
	@rm -rf PatternTown	
	@rm -rf obj
	@mkdir obj



##############################################
# Nettoyage des dossiers

SOURCESTILDE=$(foreach sdir, $(SRCDIR), $(wildcard $(sdir)/*.cpp~))
INCLUDESTILDE=$(foreach idir, $(IDIR), $(wildcard $(idir)/*.hpp~))

clean:
	@rm -rf core *~ $(OBJECTS) $(EXEC) $(SOURCESTILDE) $(INCLUDESTILDE)



##############################################
# Generation de la documentation Doxygen

doc:
	@rm -rf doc
	@doxygen Doxyfile
