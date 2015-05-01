DEMODIR = $(GFXLIB)/demos/3rdparty/doom
GFXINC +=   $(DEMODIR)
GFXSRC +=	\
		$(DEMODIR)/d_main.c			\
		$(DEMODIR)/i_main.c			\
		$(DEMODIR)/i_system.c		\
		$(DEMODIR)/i_sound.c		\
		$(DEMODIR)/i_video.c		\
		$(DEMODIR)/i_net.c			\
		$(DEMODIR)/doomdef.c		\
		$(DEMODIR)/doomstat.c		\
		$(DEMODIR)/dstrings.c		\
		$(DEMODIR)/tables.c			\
		$(DEMODIR)/f_finale.c		\
		$(DEMODIR)/f_wipe.c 		\
		$(DEMODIR)/d_net.c			\
		$(DEMODIR)/d_items.c		\
		$(DEMODIR)/g_game.c			\
		$(DEMODIR)/m_menu.c			\
		$(DEMODIR)/m_misc.c			\
		$(DEMODIR)/m_argv.c  		\
		$(DEMODIR)/m_bbox.c			\
		$(DEMODIR)/m_fixed.c		\
		$(DEMODIR)/m_swap.c			\
		$(DEMODIR)/m_cheat.c		\
		$(DEMODIR)/m_random.c		\
		$(DEMODIR)/am_map.c			\
		$(DEMODIR)/p_ceilng.c		\
		$(DEMODIR)/p_doors.c		\
		$(DEMODIR)/p_enemy.c		\
		$(DEMODIR)/p_floor.c		\
		$(DEMODIR)/p_inter.c		\
		$(DEMODIR)/p_lights.c		\
		$(DEMODIR)/p_map.c			\
		$(DEMODIR)/p_maputl.c		\
		$(DEMODIR)/p_plats.c		\
		$(DEMODIR)/p_pspr.c			\
		$(DEMODIR)/p_setup.c		\
		$(DEMODIR)/p_sight.c		\
		$(DEMODIR)/p_spec.c			\
		$(DEMODIR)/p_switch.c		\
		$(DEMODIR)/p_mobj.c			\
		$(DEMODIR)/p_telept.c		\
		$(DEMODIR)/p_tick.c			\
		$(DEMODIR)/p_saveg.c		\
		$(DEMODIR)/p_user.c			\
		$(DEMODIR)/r_bsp.c			\
		$(DEMODIR)/r_data.c			\
		$(DEMODIR)/r_draw.c			\
		$(DEMODIR)/r_main.c			\
		$(DEMODIR)/r_plane.c		\
		$(DEMODIR)/r_segs.c			\
		$(DEMODIR)/r_sky.c			\
		$(DEMODIR)/r_things.c		\
		$(DEMODIR)/w_wad.c			\
		$(DEMODIR)/wi_stuff.c		\
		$(DEMODIR)/v_video.c		\
		$(DEMODIR)/st_lib.c			\
		$(DEMODIR)/st_stuff.c		\
		$(DEMODIR)/hu_stuff.c		\
		$(DEMODIR)/hu_lib.c			\
		$(DEMODIR)/s_sound.c		\
		$(DEMODIR)/z_zone.c			\
		$(DEMODIR)/info.c			\
		$(DEMODIR)/sounds.c
