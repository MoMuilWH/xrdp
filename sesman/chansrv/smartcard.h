/**
 * xrdp: A Remote Desktop Protocol server.
 *
 * Copyright (C) Laxmikant Rashinkar 2013 LK.Rashinkar@gmail.com
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
 *
 */

/*
 * smartcard redirection support
 */

#ifndef _SMARTCARD_C
#define _SMARTCARD_C

#include "parse.h"
#include "irp.h"
#include "trans.h"

typedef struct reader_state
{
    char   reader_name[128];
    tui32  current_state;
    tui32  event_state;
    tui32  atr_len; /* number of bytes in atr[] */
    tui8   atr[36];
} READER_STATE;

void scard_device_announce(tui32 device_id);
int  APP_CC scard_get_wait_objs(tbus *objs, int *count, int *timeout);
int  APP_CC scard_check_wait_objs(void);
int  APP_CC scard_init(void);
int  APP_CC scard_deinit(void);
int  APP_CC scard_send_irp_establish_context(struct trans *con, int scope);
int  APP_CC scard_send_irp_list_readers(struct trans *con);

int  APP_CC scard_send_irp_get_status_change(struct trans *con, int wide, tui32 timeout,
                                             tui32 num_readers, READER_STATE* rsa);
#endif /* end #ifndef _SMARTCARD_C */
