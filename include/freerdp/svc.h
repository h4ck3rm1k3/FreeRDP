/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Static Virtual Channel Interface
 *
 * Copyright 2009-2011 Jay Sorg
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_SVC_H
#define FREERDP_SVC_H

#include <freerdp/api.h>
#include <freerdp/types.h>

#include <winpr/wtsapi.h>

#define CHANNEL_EVENT_USER	1000

#define CHANNEL_EXPORT_FUNC_NAME "VirtualChannelEntry"

typedef UINT (FREERDP_CC * PVIRTUALCHANNELEVENTPUSH)(DWORD openHandle, wMessage* event);

#define FREERDP_CHANNEL_MAGIC_NUMBER	0x46524450

struct _CHANNEL_ENTRY_POINTS_FREERDP
{
	UINT32 cbSize;
	UINT32 protocolVersion;
	PVIRTUALCHANNELINIT  pVirtualChannelInit;
	PVIRTUALCHANNELOPEN  pVirtualChannelOpen;
	PVIRTUALCHANNELCLOSE pVirtualChannelClose;
	PVIRTUALCHANNELWRITE pVirtualChannelWrite;

	/* Extended Fields */
	UINT32 MagicNumber; /* identifies FreeRDP */
	void* pExtendedData; /* extended initial data */
	void* pInterface; /* channel callback interface, use after initialization */
	void** ppInterface; /* channel callback interface, use for initialization */
	PVIRTUALCHANNELEVENTPUSH pVirtualChannelEventPush;
};
typedef struct _CHANNEL_ENTRY_POINTS_FREERDP CHANNEL_ENTRY_POINTS_FREERDP;
typedef CHANNEL_ENTRY_POINTS_FREERDP* PCHANNEL_ENTRY_POINTS_FREERDP;

#endif /* FREERDP_SVC_H */
