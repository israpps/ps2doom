BINDIR ?= ../bin/
BINNAME ?= DOOM

EE_BIN = $(BINDIR)$(BINNAME)_unc.ELF
EE_BIN_PKD = $(BINDIR)$(BINNAME).ELF

ARCADE ?= 0

EE_INCS = -I$(PS2SDK)/ports/include -I$(PS2SDK)/ports/include/SDL -I$(PS2SDK)/ports/include/zlib
EE_LIBS = -L$(PS2SDK)/ports/lib -lsdlmixer -lsdl -lc -lm -ldebug -lfileXio

EE_CFLAGS = -DUSE_RWOPS -DHAVE_CONFIG_H -DHAVE_MIXER
EE_CFLAGS += -D__GITHASH__=\"$(shell git rev-parse --short HEAD)\"
EE_CXXFLAGS = -DSYS_LITTLE_ENDIAN -DSYS_NEED_ALIGNMENT -DBYPASS_PROTECTION -DUSE_RWOPS -DHAVE_CONFIG_H -DHAVE_MIXER

EE_OBJS  = l_sdl.o \
l_video_trans.o l_video_sdl.o \
l_sound_sdl.o mmus2mid.o am_map.o \
g_game.o p_mobj.o r_segs.o hu_lib.o \
lprintf.o p_plats.o r_sky.o d_deh.o \
hu_stuff.o m_argv.o p_pspr.o m_bbox.o \
p_saveg.o r_things.o d_items.o m_cheat.o \
p_setup.o s_sound.o d_main.o p_sight.o \
sounds.o m_menu.o p_spec.o info.o \
st_lib.o m_misc.o p_switch.o l_joy.o \
p_telept.o st_stuff.o m_random.o p_tick.o \
l_main.o tables.o p_user.o l_system.o \
p_ceilng.o v_video.o doomdef.o p_doors.o \
p_enemy.o r_bsp.o version.o doomstat.o \
p_floor.o r_data.o w_wad.o p_genlin.o \
dstrings.o p_inter.o wi_stuff.o r_draw.o \
f_finale.o p_lights.o z_bmalloc.o p_map.o \
r_main.o f_wipe.o z_zone.o p_maputl.o \
r_plane.o d_client.o l_udp.o \
usbd.s bdm.s bdmfs_fatfs.s usbmass_bd.s sio2man.s fileXio.s iomanX.s


ifeq ($(ARCADE),1)
  BINNAME = ACDOOM
  EE_CFLAGS += -DARCADE
  IOPRP = iop/IOPRP.IMG
  EE_OBJS += dongleman.s

$(IOPRP):
	wget "https://github.com/PS2Homebrew-arcade/proverb/raw/refs/heads/main/ioprp.img" -O $@

else
  EE_OBJS += mcman.s
endif

ifdef IOPRP
  EE_CFLAGS += -DIOPRP
  EE_LIBS += -liopreboot
  EE_OBJS += ioprp.s

ioprp.s: $(IOPRP)
	bin2s $< $@ ioprp_img
endif

all: $(EE_BIN_PKD) $(BINDIR)

$(EE_BIN_PKD): $(EE_BIN)
	ps2-packer $(EE_BIN) $(EE_BIN_PKD)

release: clean all
	cp ../data/boomlump.wad $(BINDIR)boomlump.wad
	rm -f $(EE_BIN)

$(BINDIR):
	mkdir -p $@

IRXTAG=$(notdir $(addsuffix _irx, $(basename $<)))

vpath %.irx iop/
vpath %.irx $(PS2SDK)/iop/irx/

%.s: %.irx
	bin2s $< $@ $(IRXTAG)
	
clean:
	rm -f $(EE_BIN) $(EE_OBJS) *.img


include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
