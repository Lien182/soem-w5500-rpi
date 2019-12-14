#ifndef _PDO_DEF_
#define _PDO_DEF_

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>


typedef struct PACKED
{
		uint16		VoltageSign:1;
		uint16		Overvoltage:1;
		uint16		Overcurrent:1;
		uint16		InaccVoltage:1;
		uint16		InaccCurrent:1;
		uint16		VoltageGuardWarning:1;
		uint16		VoltageGuardError:1;
		uint16		CurrentGuardWarning:1;
		uint16		CurrentGuardError:1;
		uint16		empty:6;
		uint16		TxPDOToggle:1;
} EL3453_status;

typedef struct PACKED
{
		uint16		SystemState:1;
		uint16		GridDirection:1;
		uint16		FrequencyGuardWarning:1;
		uint16		FrequencyGuardError:1;
		uint16		NeutralCurrentGuardWarning:1;
		uint16		NeutralCurrentGuardError:1;
		uint16		ActivePowerGuardWarning:1;
		uint16		ActivePowerGuardError:1;
		uint16		ApparentPowerGuardWarning:1;
		uint16		ApparentPowerGuardError:1;
		uint16		PowerQualityGuardWarning:1;
		uint16		PowerQualityGuardError:1;
		uint16		empty:2;
		uint16		TxPDOState:1;
		uint16		TxPDOToggle:1;
} EL3453_status_total;


typedef struct PACKED
{
		EL3453_status	status;
		float			Voltage;
		float 			Current;
		float 			ActivePower;
		float 			ApparentPower;
		float 			ReactivePower;
		float			PowerFactor;
} EL3453_channel;

typedef struct PACKED
{
		EL3453_status_total	status;
		float				PowerQualityFactor;
} EL3453_total;

typedef struct PACKED
{
	EL3453_channel chx[3];
	EL3453_total   total;		
} EL3453_TxPDO;

typedef struct PACKED
{
		uint16		Index1REAL;
		uint16		Index2REAL;
		uint16		Index3REAL;
		uint16		Index4ULINT;
} EL3453_RxPDO;

typedef struct PACKED{
	EL3453_RxPDO 	RxPDO;
	EL3453_TxPDO 	TxPDO;
} slave_EL3453_t;

#endif //_PDO_DEF_
