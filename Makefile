PROFILE     = cd-extended.sh
CDSHELL     = cd.sh
EXSHELL     = ex.sh
SHELLDIR    = script
DIRCTL      = dirctl
SRCDIR      = src
INSTALL_DIR = /usr/local/share/cd-extended
PROFILE_DIR = /etc/profile.d

all:
	$(MAKE) -C $(SRCDIR)
	chmod +x $(patsubst %,$(SHELLDIR)/%,$(PROFILE) $(CDSHELL) $(EXSHELL))

clean:
	$(MAKE) -C $(SRCDIR) clean

install: $(SRCDIR)/$(DIRCTL)
	mkdir -p $(INSTALL_DIR)
	cp $(SRCDIR)/$(DIRCTL) $(INSTALL_DIR)
	cp $(SHELLDIR)/$(CDSHELL) $(INSTALL_DIR)
	cp $(SHELLDIR)/$(EXSHELL) $(INSTALL_DIR)
	cp $(SHELLDIR)/$(PROFILE) $(PROFILE_DIR)

uninstall:
	rm -f $(PROFILE_DIR)/$(PROFILE)
	rm -f $(INSTALL_DIR)/$(DIRCTL)
	rm -f $(INSTALL_DIR)/$(CDSHELL)
	rm -f $(INSTALL_DIR)/$(EXSHELL)

.PHONT: all clean install uninstall
