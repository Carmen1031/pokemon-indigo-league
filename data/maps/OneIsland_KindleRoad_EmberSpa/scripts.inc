OneIsland_KindleRoad_EmberSpa_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end
