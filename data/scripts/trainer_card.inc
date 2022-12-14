.set LOCALID_STICKER_MAN, 1

CeladonCity_GameCorner_EventScript_PhotoPrinter::
	lockall
	showmoneybox 0, 0, 0
	msgbox CeladonCity_GameCorner_Text_TryPokemonPrinter, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CeladonCity_GameCorner_EventScript_DeclinePhoto
	checkmoney 50, 0
	compare VAR_RESULT, FALSE
	goto_if_eq CeladonCity_GameCorner_EventScript_NotEnoughMoneyForPhoto
	playse SE_SHOP
	removemoney 50, 0
	updatemoneybox 0, 0, 0
	waitse
	message CeladonCity_GameCorner_Text_ChoosePrintType
	waitmessage
	multichoice 21, 0, MULTICHOICE_TRAINER_CARD_ICON_TINT, TRUE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_EventScript_PrintTypeNormal
	case 1, CeladonCity_GameCorner_EventScript_PrintTypeBlack
	case 2, CeladonCity_GameCorner_EventScript_PrintTypePink
	case 3, CeladonCity_GameCorner_EventScript_PrintTypeSepia
	end

CeladonCity_GameCorner_EventScript_PrintTypeNormal::
	setvar VAR_0x8004, MON_ICON_TINT_NORMAL
	goto CeladonCity_GameCorner_EventScript_PrintPhoto
	end

CeladonCity_GameCorner_EventScript_PrintTypeBlack::
	setvar VAR_0x8004, MON_ICON_TINT_BLACK
	goto CeladonCity_GameCorner_EventScript_PrintPhoto
	end

CeladonCity_GameCorner_EventScript_PrintTypePink::
	setvar VAR_0x8004, MON_ICON_TINT_PINK
	goto CeladonCity_GameCorner_EventScript_PrintPhoto
	end

CeladonCity_GameCorner_EventScript_PrintTypeSepia::
	setvar VAR_0x8004, MON_ICON_TINT_SEPIA
	goto CeladonCity_GameCorner_EventScript_PrintPhoto
	end

CeladonCity_GameCorner_EventScript_PrintPhoto::
	message CeladonCity_GameCorner_Text_BigSmileForPhoto
	waitmessage
	playse MUS_PHOTO
	dofieldeffect FLDEFF_UNK_45
	delay 60
	special UpdateTrainerCardPhotoIcons
	msgbox CeladonCity_GameCorner_Text_PrintIsReadyCheckTrainerCard
	hidemoneybox 0, 0
	releaseall
	end

CeladonCity_GameCorner_EventScript_DeclinePhoto::
	hidemoneybox 0, 0
	releaseall
	end

CeladonCity_GameCorner_EventScript_NotEnoughMoneyForPhoto::
	msgbox CeladonCity_GameCorner_Text_DontHaveEnoughMoney
	hidemoneybox 0, 0
	releaseall
	end

FourIsland_House2_EventScript_StickerMan::
	lock
	specialvar VAR_0x8008, StickerManGetBragFlags
	goto_if_unset FLAG_MET_STICKER_MAN, FourIsland_House2_EventScript_MeetStickerMan
	goto_if_set FLAG_MET_STICKER_MAN, FourIsland_House2_EventScript_StickerManAskForBrag
	end

FourIsland_House2_EventScript_MeetStickerMan::
	setflag FLAG_MET_STICKER_MAN
	msgbox FourIsland_House2_Text_WishICouldShowOffStickers
	applymovement LOCALID_STICKER_MAN, Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_STICKER_MAN, Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STICKER_MAN, Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	goto_if_eq FourIsland_House2_EventScript_StickerManNothingToBrag
	message FourIsland_House2_Text_GiveYouStickerIfYouBrag
	waitmessage
	goto FourIsland_House2_EventScript_ChooseBrag
	end

FourIsland_House2_EventScript_StickerManAskForBrag::
	applymovement LOCALID_STICKER_MAN, Movement_FacePlayer
	waitmovement 0
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	compare VAR_0x8008, 0
	goto_if_eq FourIsland_House2_EventScript_NothingToBragAbout
	message FourIsland_House2_Text_BragAboutWhatToday
	waitmessage
	goto FourIsland_House2_EventScript_ChooseBrag
	end

FourIsland_House2_EventScript_NothingToBragAbout::
	msgbox FourIsland_House2_Text_BragAboutSomethingForMe
	release
	end

FourIsland_House2_EventScript_ChooseBrag::
	switch VAR_0x8008
	case 1, FourIsland_House2_EventScript_ChooseBragHoF
	case 2, FourIsland_House2_EventScript_ChooseBragEggs
	case 4, FourIsland_House2_EventScript_ChooseBragLinkWins
	case 3, FourIsland_House2_EventScript_ChooseBragHoFEggs
	case 5, FourIsland_House2_EventScript_ChooseBragHoFLinkWins
	case 6, FourIsland_House2_EventScript_ChooseBragEggsLinkWins
	case 7, FourIsland_House2_EventScript_ChooseBragHofEggsLinkWins
	end

FourIsland_House2_EventScript_ChooseBragHoF::
	multichoice 15, 8, MULTICHOICE_HOF_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragHoF
	case 1, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragEggs::
	multichoice 16, 8, MULTICHOICE_EGGS_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragEggs
	case 1, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragLinkWins::
	multichoice 15, 8, MULTICHOICE_VICTORIES_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragLinkWins
	case 1, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragHoFEggs::
	multichoice 15, 6, MULTICHOICE_HOF_EGGS_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragHoF
	case 1, FourIsland_House2_EventScript_BragEggs
	case 2, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragHoFLinkWins::
	multichoice 15, 6, MULTICHOICE_HOF_VICTORIES_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragHoF
	case 1, FourIsland_House2_EventScript_BragLinkWins
	case 2, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragEggsLinkWins::
	multichoice 15, 6, MULTICHOICE_EGGS_VICTORIES_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragEggs
	case 1, FourIsland_House2_EventScript_BragLinkWins
	case 2, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_ChooseBragHofEggsLinkWins::
	multichoice 15, 5, MULTICHOICE_HOF_EGGS_VICTORIES_QUIT, FALSE
	switch VAR_RESULT
	case 0, FourIsland_House2_EventScript_BragHoF
	case 1, FourIsland_House2_EventScript_BragEggs
	case 2, FourIsland_House2_EventScript_BragLinkWins
	case 3, FourIsland_House2_EventScript_QuitBrag
	case SCR_MENU_CANCEL, FourIsland_House2_EventScript_QuitBrag
	end

FourIsland_House2_EventScript_StickerManNothingToBrag::
	msgbox FourIsland_House2_Text_GiveYouStickerIfYouBrag
	release
	end

FourIsland_House2_EventScript_BragHoF::
	compare VAR_0x8004, 39
	goto_if_le FourIsland_House2_EventScript_BragHoFLowest
	compare VAR_0x8004, 99
	goto_if_le FourIsland_House2_EventScript_BragHoFLow
	compare VAR_0x8004, 199
	goto_if_le FourIsland_House2_EventScript_BragHoFHigh
	compare VAR_0x8004, 200
	goto_if_ge FourIsland_House2_EventScript_BragHoFHighest
	end

FourIsland_House2_EventScript_BragHoFLowest::
	compare VAR_HOF_BRAG_STATE, 1
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedHoF
	setvar VAR_HOF_BRAG_STATE, 1
	msgbox FourIsland_House2_Text_WowHoFLowest
	goto FourIsland_House2_EventScript_BraggedHoF
	end

FourIsland_House2_EventScript_BragHoFLow::
	compare VAR_HOF_BRAG_STATE, 2
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedHoF
	setvar VAR_HOF_BRAG_STATE, 2
	msgbox FourIsland_House2_Text_WowHoFLow
	goto FourIsland_House2_EventScript_BraggedHoF
	end

FourIsland_House2_EventScript_BragHoFHigh::
	compare VAR_HOF_BRAG_STATE, 3
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedHoF
	setvar VAR_HOF_BRAG_STATE, 3
	msgbox FourIsland_House2_Text_WowHoFHigh
	goto FourIsland_House2_EventScript_BraggedHoF
	end

FourIsland_House2_EventScript_BragHoFHighest::
	compare VAR_HOF_BRAG_STATE, 4
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedHoFMax
	setvar VAR_HOF_BRAG_STATE, 4
	msgbox FourIsland_House2_Text_WowHoFHighest
	goto FourIsland_House2_EventScript_BraggedHoF
	end

FourIsland_House2_EventScript_AlreadyBraggedHoF::
	msgbox FourIsland_House2_Text_ComeBackWithBetterStoryHoF
	release
	end

FourIsland_House2_EventScript_AlreadyBraggedHoFMax::
	msgbox FourIsland_House2_Text_LivingLegendHoF
	release
	end

FourIsland_House2_EventScript_BraggedHoF::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message FourIsland_House2_Text_HoFStickerApplied
	waitmessage
	waitfanfare
	delay 90
	release
	end

FourIsland_House2_EventScript_BragEggs::
	compare VAR_0x8005, 99
	goto_if_le FourIsland_House2_EventScript_BragEggsLowest
	compare VAR_0x8005, 199
	goto_if_le FourIsland_House2_EventScript_BragEggsLow
	compare VAR_0x8005, 299
	goto_if_le FourIsland_House2_EventScript_BragEggsHigh
	compare VAR_0x8005, 300
	goto_if_ge FourIsland_House2_EventScript_BragEggsHighest
	end

FourIsland_House2_EventScript_BragEggsLowest::
	compare VAR_EGG_BRAG_STATE, 1
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedEggs
	setvar VAR_EGG_BRAG_STATE, 1
	msgbox FourIsland_House2_Text_WowEggsLowest
	goto FourIsland_House2_EventScript_BraggedEggs
	end

FourIsland_House2_EventScript_BragEggsLow::
	compare VAR_EGG_BRAG_STATE, 2
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedEggs
	setvar VAR_EGG_BRAG_STATE, 2
	msgbox FourIsland_House2_Text_WowEggsLow
	goto FourIsland_House2_EventScript_BraggedEggs
	end

FourIsland_House2_EventScript_BragEggsHigh::
	compare VAR_EGG_BRAG_STATE, 3
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedEggs
	setvar VAR_EGG_BRAG_STATE, 3
	msgbox FourIsland_House2_Text_WowEggsHigh
	goto FourIsland_House2_EventScript_BraggedEggs
	end

FourIsland_House2_EventScript_BragEggsHighest::
	compare VAR_EGG_BRAG_STATE, 4
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedEggsMax
	setvar VAR_EGG_BRAG_STATE, 4
	msgbox FourIsland_House2_Text_WowEggsHighest
	goto FourIsland_House2_EventScript_BraggedEggs
	end

FourIsland_House2_EventScript_AlreadyBraggedEggs::
	msgbox FourIsland_House2_Text_ComeBackWithBetterStoryEggs
	release
	end

FourIsland_House2_EventScript_AlreadyBraggedEggsMax::
	msgbox FourIsland_House2_Text_LivingLegendEggs
	release
	end

FourIsland_House2_EventScript_BraggedEggs::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message FourIsland_House2_Text_EggStickerApplied
	waitmessage
	waitfanfare
	delay 90
	release
	end

FourIsland_House2_EventScript_BragLinkWins::
	compare VAR_0x8006, 19
	goto_if_le FourIsland_House2_EventScript_BragLinkWinsLowest
	compare VAR_0x8006, 49
	goto_if_le FourIsland_House2_EventScript_BragLinkWinsLow
	compare VAR_0x8006, 99
	goto_if_le FourIsland_House2_EventScript_BragLinkWinsHigh
	compare VAR_0x8006, 100
	goto_if_ge FourIsland_House2_EventScript_BragLinkWinsHighest
	end

FourIsland_House2_EventScript_BragLinkWinsLowest::
	compare VAR_LINK_WIN_BRAG_STATE, 1
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedLinkWins
	setvar VAR_LINK_WIN_BRAG_STATE, 1
	msgbox FourIsland_House2_Text_WowLinkWinsLowest
	goto FourIsland_House2_EventScript_BraggedLinkWins
	end

FourIsland_House2_EventScript_BragLinkWinsLow::
	compare VAR_LINK_WIN_BRAG_STATE, 2
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedLinkWins
	setvar VAR_LINK_WIN_BRAG_STATE, 2
	msgbox FourIsland_House2_Text_WowLinkWinsLow
	goto FourIsland_House2_EventScript_BraggedLinkWins
	end

FourIsland_House2_EventScript_BragLinkWinsHigh::
	compare VAR_LINK_WIN_BRAG_STATE, 3
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedLinkWins
	setvar VAR_LINK_WIN_BRAG_STATE, 3
	msgbox FourIsland_House2_Text_WowLinkWinsHigh
	goto FourIsland_House2_EventScript_BraggedLinkWins
	end

FourIsland_House2_EventScript_BragLinkWinsHighest::
	compare VAR_LINK_WIN_BRAG_STATE, 4
	goto_if_eq FourIsland_House2_EventScript_AlreadyBraggedLinkWinsMax
	setvar VAR_LINK_WIN_BRAG_STATE, 4
	msgbox FourIsland_House2_Text_WowLinkWinsHighest
	goto FourIsland_House2_EventScript_BraggedLinkWins
	end

FourIsland_House2_EventScript_AlreadyBraggedLinkWins::
	msgbox FourIsland_House2_Text_ComeBackWithBetterStoryLinkWins
	release
	end

FourIsland_House2_EventScript_AlreadyBraggedLinkWinsMax::
	msgbox FourIsland_House2_Text_LivingLegendLinkWins
	release
	end

FourIsland_House2_EventScript_BraggedLinkWins::
	textcolor 3
	playfanfare MUS_LEVEL_UP
	message FourIsland_House2_Text_VictoryStickerApplied
	waitmessage
	waitfanfare
	delay 90
	release
	end

FourIsland_House2_EventScript_QuitBrag::
	release
	end
