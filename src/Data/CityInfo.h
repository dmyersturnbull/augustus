#ifndef DATA_CITYINFO_H
#define DATA_CITYINFO_H

#include <stdint.h>

extern struct _Data_CityInfo {
	int8_t __unknown_00a5;
	int32_t populationMaxSupported;
	int32_t populationRoomInHouses;
	int32_t populationLastTargetHouseAdd;
	int32_t populationLastTargetHouseRemove;
	int16_t resourceLastTargetWarehouse;
	int32_t numProtestersThisMonth;
	int32_t numCriminalsThisMonth; // muggers+rioters
	int32_t numRiotersInCity;
	int16_t numAnimalsInCity;
	int32_t riotersOrAttackingNativesInCity;
	int32_t nativeAttackDuration;
	int32_t nativeMissionPostOperational;
	int32_t nativeMainMeetingCenterX;
	int32_t nativeMainMeetingCenterY;
	int32_t tutorial1SenateBuilt;
	int32_t numEnemiesInCity;
	int32_t numImperialSoldiersInCity;
	uint8_t distantBattleCityId;
	uint8_t distantBattleEnemyStrength;
	uint8_t distantBattleRomanStrength;
	int8_t distantBattleMonthsToBattle;
	int8_t distantBattleRomanMonthsToReturn;
	int8_t distantBattleRomanMonthsToTravel;
	int8_t distantBattleCityMonthsUntilRoman;
	int8_t distantBattleTotalCount;
	int8_t distantBattleWonCount;
	int8_t distantBattleEnemyMonthsTraveled;
	int8_t distantBattleRomanMonthsTraveled;
	int8_t militaryTotalLegions;
	int8_t militaryTotalLegionsEmpireService;
	int8_t militaryTotalSoldiers;
	int32_t numSoldiersInCity;
	int32_t militaryLegionaryLegions;
	int32_t missionSavedGameWritten;
	int32_t tutorial1FireMessageShown;
	int32_t tutorial3DiseaseMessageShown;
	int32_t numAttackingNativesInCity;

	int32_t populationGraphOrder;
	int32_t ciid;
} Data_CityInfo;

#endif
