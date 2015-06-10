rt_inside_reg_assign:
    i = rec.v1.inside_r.reg;
    j = rec.v1.inside_r.d_byte;
    l = rec.v1.inside_r.s_byte;

    dc->reg_dirty_tbl[i][j] = dc->reg_dirty_tbl[i][l];
    THREADED_DISPATCH();

rt_inside_reg_append:
    i = rec.v1.inside_r.reg;
    j = rec.v1.inside_r.d_byte;
    l = rec.v1.inside_r.s_byte;

    dc->reg_dirty_tbl[i][j] |= dc->reg_dirty_tbl[i][l];
    THREADED_DISPATCH();

rt_reg_reg_oo_assign_mo8:
    i = rec.v1.r2r_byte.dreg;
    k = rec.v1.r2r_byte.dreg_byte;
    j = rec.v1.r2r_byte.sreg;
    l = rec.v1.r2r_byte.sreg_byte;

    dc->reg_dirty_tbl[i][k] = dc->reg_dirty_tbl[j][l];
    THREADED_DISPATCH();

rt_reg_reg_oo_assign_mo16:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint16_t*)&dc->reg_dirty_tbl[i][0] = *(uint16_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_oo_assign_mo32:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint32_t*)&dc->reg_dirty_tbl[i][0] = *(uint32_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_oo_assign_mo64:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint64_t*)&dc->reg_dirty_tbl[i][0] = *(uint64_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_oo_append_mo8:
    j = rec.v1.r2r_byte.sreg;
    l = rec.v1.r2r_byte.sreg_byte;
    i = rec.v1.r2r_byte.dreg;
    k = rec.v1.r2r_byte.dreg_byte;

    dc->reg_dirty_tbl[i][k] |= dc->reg_dirty_tbl[j][l];
    THREADED_DISPATCH();

rt_reg_reg_oo_append_mo16:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint16_t*)&dc->reg_dirty_tbl[i][0] |= *(uint16_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_oo_append_mo32:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint32_t*)&dc->reg_dirty_tbl[i][0] |= *(uint32_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_oo_append_mo64:
    i = rec.v1.r2r.dreg;
    j = rec.v1.r2r.sreg;

    *(uint64_t*)&dc->reg_dirty_tbl[i][0] |= *(uint64_t*)&dc->reg_dirty_tbl[j][0];
    THREADED_DISPATCH();

rt_reg_reg_mix_append_mo16:
    j = rec.v1.r2r.sreg;
    i = rec.v1.r2r.dreg;
    t = dc->reg_dirty_tbl[j][0] | dc->reg_dirty_tbl[j][1]
        | dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1];

    dc->reg_dirty_tbl[i][0] |= t;
    dc->reg_dirty_tbl[i][1] |= t;
    THREADED_DISPATCH();

rt_reg_reg_mix_append_mo32:
    j = rec.v1.r2r.sreg;
    i = rec.v1.r2r.dreg;

    dc->reg_dirty_tbl[i][0] |=
        dc->reg_dirty_tbl[j][0] | dc->reg_dirty_tbl[j][1]
        | dc->reg_dirty_tbl[j][2] | dc->reg_dirty_tbl[j][3]
        | dc->reg_dirty_tbl[i][1] | dc->reg_dirty_tbl[i][2]
        | dc->reg_dirty_tbl[i][3];
    dc->reg_dirty_tbl[i][1] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][2] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][3] = dc->reg_dirty_tbl[i][0];
    THREADED_DISPATCH();

rt_reg_reg_mix_append_mo64:
    j = rec.v1.r2r.sreg;
    i = rec.v1.r2r.dreg;

    dc->reg_dirty_tbl[i][0] |=
          dc->reg_dirty_tbl[j][0] | dc->reg_dirty_tbl[j][1]
        | dc->reg_dirty_tbl[j][2] | dc->reg_dirty_tbl[j][3]
        | dc->reg_dirty_tbl[j][4] | dc->reg_dirty_tbl[j][5]
        | dc->reg_dirty_tbl[j][6] | dc->reg_dirty_tbl[j][7]
        | dc->reg_dirty_tbl[i][1] | dc->reg_dirty_tbl[i][2]
        | dc->reg_dirty_tbl[i][3] | dc->reg_dirty_tbl[i][4]
        | dc->reg_dirty_tbl[i][5] | dc->reg_dirty_tbl[i][6]
        | dc->reg_dirty_tbl[i][7];

    dc->reg_dirty_tbl[i][1] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][2] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][3] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][4] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][5] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][6] = dc->reg_dirty_tbl[i][0];
    dc->reg_dirty_tbl[i][7] = dc->reg_dirty_tbl[i][0];
    THREADED_DISPATCH();   

rt_reg_mem_oo_assign_mo8:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r_byte.reg;
    k = rec.v1.r2m_m2r_byte.hl;
#if defined(CONFIG_INDIRECT_TAINT)
    j = rec.v1.r2m_m2r_byte.reg_base;
    l = rec.v1.r2m_m2r_byte.reg_index;
#endif

#if defined(CONFIG_INDIRECT_TAINT)
    dc->reg_dirty_tbl[i][k] = get_mem_dirty(dc, ra) |
                        dc->reg_dirty_tbl[j][0] |
                        dc->reg_dirty_tbl[l][0];

#else
    dc->reg_dirty_tbl[i][k] = get_mem_dirty(dc, ra);
#endif
    THREADED_DISPATCH();

rt_reg_mem_oo_assign_mo16:
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_INDIRECT_TAINT)
    j = rec.v1.r2m_m2r.reg_base;
    l = rec.v1.r2m_m2r.reg_index;
#endif
    i = rec.v1.r2m_m2r.reg;

#if defined(CONFIG_INDIRECT_TAINT)
    t = dc->reg_dirty_tbl[j][0] | dc->reg_dirty_tbl[j][1] |
        dc->reg_dirty_tbl[l][0] | dc->reg_dirty_tbl[l][1];
    dc->reg_dirty_tbl[i][0] = get_mem_dirty(dc, ra) | t;
    dc->reg_dirty_tbl[i][1] = get_mem_dirty(dc, ra + 1) | t;
#else
    dc->reg_dirty_tbl[i][0] = get_mem_dirty(dc, ra);
    dc->reg_dirty_tbl[i][1] = get_mem_dirty(dc, ra + 1);
#endif
    THREADED_DISPATCH();

rt_reg_mem_oo_assign_mo32:
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_INDIRECT_TAINT)
    //j = rec.v1.r2m_m2r.reg_base;
    //l = rec.v1.r2m_m2r.reg_index;
#endif
    i = rec.v1.r2m_m2r.reg;

#if defined(CONFIG_INDIRECT_TAINT)
    *(uint32_t*)&dc->reg_dirty_tbl[i][0] = *(uint32_t*)&dc->mem_dirty_tbl[ra];
#else
    *(uint32_t*)&dc->reg_dirty_tbl[i][0] = *(uint32_t*)&dc->mem_dirty_tbl[ra];
#endif

    THREADED_DISPATCH();

rt_reg_mem_oo_assign_mo64:
    ra = DEQ_FROM_ADDR();
    i = rec.vl.r2m_m2r.reg;

    *(uint64_t*)&dc->reg_dirty_tbl[i][0] = *(uint64_t*)&dc->mem_dirty_tbl[ra];

    THREADED_DISPATCH();

rt_reg_mem_oo_append_mo8:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r_byte.reg;
    k = rec.v1.r2m_m2r_byte.hl;
#if defined(CONFIG_INDIRECT_TAINT)
    //j = rec.v1.r2m_m2r_byte.reg_base;
    //l = rec.v1.r2m_m2r_byte.reg_index;
#endif
    t = get_mem_dirty(dc, ra);

    dc->reg_dirty_tbl[i][k] |= t;
    THREADED_DISPATCH();

rt_reg_mem_oo_append_mo16:
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_INDIRECT_TAINT)
    //j = rec.v1.r2m_m2r.reg_base;
    //l = rec.v1.r2m_m2r.reg_index;
#endif
    i = rec.v1.r2m_m2r.reg;
    t = get_mem_dirty(dc, ra);
    dc->reg_dirty_tbl[i][0] |= t;

    t = get_mem_dirty(dc, ra + 1);
    dc->reg_dirty_tbl[i][1] |= t;
    THREADED_DISPATCH();

rt_reg_mem_oo_append_mo32:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;

    *(uint32_t*)&dc->reg_dirty_tbl[i][0] |= *(uint32_t*)&dc->mem_dirty_tbl[ra];
    THREADED_DISPATCH();

rt_reg_mem_oo_append_mo64:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;

    *(uint64_t*)&dc->reg_dirty_tbl[i][0] |= *(uint64_t*)&dc->mem_dirty_tbl[ra];
    THREADED_DISPATCH();

rt_reg_mem_mix_assign_mo16:
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_INDIRECT_TAINT)
    //j = rec.v1.r2m_m2r.reg_base;
    //l = rec.v1.r2m_m2r.reg_index;
#endif
    i = rec.v1.r2m_m2r.reg;
    t = get_mem_dirty(dc, ra) | get_mem_dirty(dc, ra + 1);
    dc->reg_dirty_tbl[i][0] = t;
    dc->reg_dirty_tbl[i][1] = t;
    THREADED_DISPATCH();

rt_reg_mem_mix_assign_mo32:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;

    t =   get_mem_dirty(dc, ra)     | get_mem_dirty(dc, ra + 1)
        | get_mem_dirty(dc, ra + 2) | get_mem_dirty(dc, ra + 3);

    dc->reg_dirty_tbl[i][0] = t;
    dc->reg_dirty_tbl[i][1] = t;
    dc->reg_dirty_tbl[i][2] = t;
    dc->reg_dirty_tbl[i][3] = t;
    THREADED_DISPATCH();

rt_reg_mem_mix_assign_mo64:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;

    t =   get_mem_dirty(dc, ra)     | get_mem_dirty(dc, ra + 1)
        | get_mem_dirty(dc, ra + 2) | get_mem_dirty(dc, ra + 3)
        | get_mem_dirty(dc, ra + 4) | get_mem_dirty(dc, ra + 5)
        | get_mem_dirty(dc, ra + 6) | get_mem_dirty(dc, ra + 7);

    dc->reg_dirty_tbl[i][0] = t;
    dc->reg_dirty_tbl[i][1] = t;
    dc->reg_dirty_tbl[i][2] = t;
    dc->reg_dirty_tbl[i][3] = t;
    dc->reg_dirty_tbl[i][4] = t;
    dc->reg_dirty_tbl[i][5] = t;
    dc->reg_dirty_tbl[i][6] = t;
    dc->reg_dirty_tbl[i][7] = t;
    THREADED_DISPATCH();

rt_reg_mem_mix_append_mo16:
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_INDIRECT_TAINT)
    //j = rec.v1.r2m_m2r.reg_base;
    //l = rec.v1.r2m_m2r.reg_index;
#endif
    i = rec.v1.r2m_m2r.reg;
    t = get_mem_dirty(dc, ra) | get_mem_dirty(dc, ra + 1)
        | dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1];
    dc->reg_dirty_tbl[i][0] |= t;
    dc->reg_dirty_tbl[i][1] |= t;
    THREADED_DISPATCH();

rt_reg_mem_mix_append_mo32:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;
    s = *(uint32_t*)&dc->mem_dirty_tbl[ra] | *(uint32_t*)&dc->reg_dirty_tbl[i][0];
    t = *((uint8_t*)&s) | *(((uint8_t*)&s) + 1) | *(((uint8_t*)&s) + 2) | *(((uint8_t*)&s) + 3);
    dc->reg_dirty_tbl[i][0] |= t;
    dc->reg_dirty_tbl[i][1] |= t;
    dc->reg_dirty_tbl[i][2] |= t;
    dc->reg_dirty_tbl[i][3] |= t;
    THREADED_DISPATCH();

rt_reg_mem_mix_append_mo64:
    ra = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r.reg;
    s = *(uint64_t*)&dc->mem_dirty_tbl[ra] | *(uint64_t*)&dc->reg_dirty_tbl[i][0];
    t =   *((uint8_t*)&s)       | *(((uint8_t*)&s) + 1)
        | *(((uint8_t*)&s) + 2) | *(((uint8_t*)&s) + 3)
        | *(((uint8_t*)&s) + 4) | *(((uint8_t*)&s) + 5)
        | *(((uint8_t*)&s) + 6) | *(((uint8_t*)&s) + 7);

    dc->reg_dirty_tbl[i][0] |= t;
    dc->reg_dirty_tbl[i][1] |= t;
    dc->reg_dirty_tbl[i][2] |= t;
    dc->reg_dirty_tbl[i][3] |= t;
    dc->reg_dirty_tbl[i][4] |= t;
    dc->reg_dirty_tbl[i][5] |= t;
    dc->reg_dirty_tbl[i][6] |= t;
    dc->reg_dirty_tbl[i][7] |= t;
    THREADED_DISPATCH();

rt_mem_reg_oo_assign_mo8:
    wa = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r_byte.reg;
    k = rec.v1.r2m_m2r_byte.hl;

    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][k], 0);
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    set_mem_dirty(dc, wa, dc->force_mem_dirty, 1);
#endif
    THREADED_DISPATCH();

rt_mem_reg_oo_assign_mo16:
    wa = DEQ_FROM_ADDR();

    i = rec.v1.r2m_m2r.reg;

#if !defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][0], 0);
    set_mem_dirty(dc, wa + 1, dc->reg_dirty_tbl[i][1], 0);
#else
    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][0] | dc->force_mem_dirty, 0);
    set_mem_dirty(dc, wa + 1, dc->reg_dirty_tbl[i][1] | dc->force_mem_dirty, 0);
#endif
    THREADED_DISPATCH();

rt_mem_reg_oo_assign_mo32:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    *(uint32_t*)&dc->mem_dirty_tbl[wa] = *(uint32_t*)&dc->reg_dirty_tbl[i][0];
    THREADED_DISPATCH();

rt_mem_reg_oo_assign_mo64:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint64_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    *(uint64_t*)&dc->mem_dirty_tbl[wa] = *(uint64_t*)&dc->reg_dirty_tbl[i][0];
    THREADED_DISPATCH();

rt_mem_reg_oo_append_mo8:
    wa = DEQ_FROM_ADDR();
    i = rec.v1.r2m_m2r_byte.reg;
    k = rec.v1.r2m_m2r_byte.hl;

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        set_mem_dirty(dc, wa, dc->force_mem_dirty, 1);
        THREADED_DISPATCH();
    }
#endif

    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][k], 1);
    THREADED_DISPATCH();

rt_mem_reg_oo_append_mo16:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint16_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][0], 1);
    set_mem_dirty(dc, wa + 1, dc->reg_dirty_tbl[i][1], 1);
    THREADED_DISPATCH();

rt_mem_reg_oo_append_mo32:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    set_mem_dirty(dc, wa, dc->reg_dirty_tbl[i][0], 1);
    set_mem_dirty(dc, wa + 1, dc->reg_dirty_tbl[i][1], 1);
    set_mem_dirty(dc, wa + 2, dc->reg_dirty_tbl[i][2], 1);
    set_mem_dirty(dc, wa + 3, dc->reg_dirty_tbl[i][3], 1);
    THREADED_DISPATCH();

rt_mem_reg_oo_append_mo64:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint64_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    set_mem_dirty(dc, wa,     dc->reg_dirty_tbl[i][0], 1);
    set_mem_dirty(dc, wa + 1, dc->reg_dirty_tbl[i][1], 1);
    set_mem_dirty(dc, wa + 2, dc->reg_dirty_tbl[i][2], 1);
    set_mem_dirty(dc, wa + 3, dc->reg_dirty_tbl[i][3], 1);
    set_mem_dirty(dc, wa + 4, dc->reg_dirty_tbl[i][4], 1);
    set_mem_dirty(dc, wa + 5, dc->reg_dirty_tbl[i][5], 1);
    set_mem_dirty(dc, wa + 6, dc->reg_dirty_tbl[i][6], 1);
    set_mem_dirty(dc, wa + 7, dc->reg_dirty_tbl[i][7], 1);
    THREADED_DISPATCH();

rt_mem_reg_mix_assign_mo16:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint16_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    t = dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1];

    set_mem_dirty(dc, wa, t, 0);
    set_mem_dirty(dc, wa + 1, t, 0);
    THREADED_DISPATCH();

rt_mem_reg_mix_assign_mo32:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    t =   dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1]
        | dc->reg_dirty_tbl[i][2] | dc->reg_dirty_tbl[i][3];


    set_mem_dirty(dc, wa, t, 0);
    set_mem_dirty(dc, wa + 1, t, 0);
    set_mem_dirty(dc, wa + 2, t, 0);
    set_mem_dirty(dc, wa + 3, t, 0);
    THREADED_DISPATCH();

rt_mem_reg_mix_assign_mo64:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    i = rec.v1.r2m_m2r.reg;
    t =   dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1]
        | dc->reg_dirty_tbl[i][2] | dc->reg_dirty_tbl[i][3]
        | dc->reg_dirty_tbl[i][4] | dc->reg_dirty_tbl[i][5]
        | dc->reg_dirty_tbl[i][6] | dc->reg_dirty_tbl[i][7];


    set_mem_dirty(dc, wa,     t, 0);
    set_mem_dirty(dc, wa + 1, t, 0);
    set_mem_dirty(dc, wa + 2, t, 0);
    set_mem_dirty(dc, wa + 3, t, 0);
    set_mem_dirty(dc, wa + 4, t, 0);
    set_mem_dirty(dc, wa + 5, t, 0);
    set_mem_dirty(dc, wa + 6, t, 0);
    set_mem_dirty(dc, wa + 7, t, 0);
    THREADED_DISPATCH();

rt_mem_reg_mix_append_mo16:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint16_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif
    i = rec.v1.r2m_m2r.reg;
    t = dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1]
        | get_mem_dirty(dc, wa) | get_mem_dirty(dc, wa + 1);

    set_mem_dirty(dc, wa, t, 1);
    set_mem_dirty(dc, wa + 1, t, 1);
    THREADED_DISPATCH();

rt_mem_reg_mix_append_mo32:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif
    i = rec.v1.r2m_m2r.reg;
    t =   dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1]
        | dc->reg_dirty_tbl[i][2] | dc->reg_dirty_tbl[i][3]
        | get_mem_dirty(dc, wa)     | get_mem_dirty(dc, wa + 1)
        | get_mem_dirty(dc, wa + 2) | get_mem_dirty(dc, wa + 3);

    set_mem_dirty(dc, wa,     t, 1);
    set_mem_dirty(dc, wa + 1, t, 1);
    set_mem_dirty(dc, wa + 2, t, 1);
    set_mem_dirty(dc, wa + 3, t, 1);
    THREADED_DISPATCH();

rt_mem_reg_mix_append_mo64:
    wa = DEQ_FROM_ADDR();

#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint64_t*)&dc->mem_dirty_tbl[wa] |= dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif
    i = rec.v1.r2m_m2r.reg;
    t =   dc->reg_dirty_tbl[i][0] | dc->reg_dirty_tbl[i][1]
        | dc->reg_dirty_tbl[i][2] | dc->reg_dirty_tbl[i][3]
        | dc->reg_dirty_tbl[i][4] | dc->reg_dirty_tbl[i][5]
        | dc->reg_dirty_tbl[i][6] | dc->reg_dirty_tbl[i][7]
        | get_mem_dirty(dc, wa)     | get_mem_dirty(dc, wa + 1)
        | get_mem_dirty(dc, wa + 2) | get_mem_dirty(dc, wa + 3)
        | get_mem_dirty(dc, wa + 4) | get_mem_dirty(dc, wa + 5)
        | get_mem_dirty(dc, wa + 6) | get_mem_dirty(dc, wa + 7);

    set_mem_dirty(dc, wa,     t, 1);
    set_mem_dirty(dc, wa + 1, t, 1);
    set_mem_dirty(dc, wa + 2, t, 1);
    set_mem_dirty(dc, wa + 3, t, 1);
    set_mem_dirty(dc, wa + 4, t, 1);
    set_mem_dirty(dc, wa + 5, t, 1);
    set_mem_dirty(dc, wa + 6, t, 1);
    set_mem_dirty(dc, wa + 7, t, 1);
    THREADED_DISPATCH();

rt_mem_mem_oo_assign_mo8:
    wa = DEQ_FROM_ADDR();
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        set_mem_dirty(dc, wa, dc->force_mem_dirty, 0);
        THREADED_DISPATCH();
    }
#endif

    set_mem_dirty(dc, wa, get_mem_dirty(dc, ra), 0);
    THREADED_DISPATCH();

rt_mem_mem_oo_assign_mo16:
    wa = DEQ_FROM_ADDR();
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint16_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    set_mem_dirty(dc, wa, get_mem_dirty(dc, ra), 0);
    set_mem_dirty(dc, wa + 1, get_mem_dirty(dc, ra + 1), 0);
    THREADED_DISPATCH();

rt_mem_mem_oo_assign_mo32:
    wa = DEQ_FROM_ADDR();
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    set_mem_dirty(dc, wa, get_mem_dirty(dc, ra), 0);
    set_mem_dirty(dc, wa + 1, get_mem_dirty(dc, ra + 1), 0);
    set_mem_dirty(dc, wa + 2, get_mem_dirty(dc, ra + 2), 0);
    set_mem_dirty(dc, wa + 3, get_mem_dirty(dc, ra + 3), 0);
    THREADED_DISPATCH();

rt_mem_mem_oo_assign_mo64:
    wa = DEQ_FROM_ADDR();
    ra = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    set_mem_dirty(dc, wa,     get_mem_dirty(dc, ra),     0);
    set_mem_dirty(dc, wa + 1, get_mem_dirty(dc, ra + 1), 0);
    set_mem_dirty(dc, wa + 2, get_mem_dirty(dc, ra + 2), 0);
    set_mem_dirty(dc, wa + 3, get_mem_dirty(dc, ra + 3), 0);
    set_mem_dirty(dc, wa + 4, get_mem_dirty(dc, ra + 4), 0);
    set_mem_dirty(dc, wa + 5, get_mem_dirty(dc, ra + 5), 0);
    set_mem_dirty(dc, wa + 6, get_mem_dirty(dc, ra + 6), 0);
    set_mem_dirty(dc, wa + 7, get_mem_dirty(dc, ra + 7), 0);
    THREADED_DISPATCH();

rt_reg_im_clear_mo8:
    i = rec.v1.r2m_m2r_byte.reg;
    k = rec.v1.r2m_m2r_byte.hl;
    dc->reg_dirty_tbl[i][k] = 0;
    THREADED_DISPATCH();

rt_reg_im_clear_mo16:
    i = rec.v1.r2m_m2r.reg;
    *(uint16_t*)&dc->reg_dirty_tbl[i][0] = 0;
    THREADED_DISPATCH();

rt_reg_im_clear_mo32:
    i = rec.v1.r2m_m2r.reg;
    *(uint32_t*)&dc->reg_dirty_tbl[i][0] = 0;
    THREADED_DISPATCH();

rt_reg_im_clear_mo64:
    i = rec.v1.r2m_m2r.reg;
    *(uint64_t*)&dc->reg_dirty_tbl[i][0] = 0;
    THREADED_DISPATCH();

rt_mem_im_clear_mo8:
    wa = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        set_mem_dirty(dc, wa, dc->force_mem_dirty, 0);
        THREADED_DISPATCH();
    }
#endif
    set_mem_dirty(dc, wa, 0, 0);
    THREADED_DISPATCH();

rt_mem_im_clear_mo16:
    wa = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint16_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif
    *(uint16_t*)&dc->mem_dirty_tbl[wa] = 0;
    THREADED_DISPATCH();

rt_mem_im_clear_mo32:
    wa = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint32_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    *(uint32_t*)&dc->mem_dirty_tbl[wa] = 0;
    THREADED_DISPATCH();

rt_mem_im_clear_mo64:
    wa = DEQ_FROM_ADDR();
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    if(dc->force_mem_dirty) {
        *(uint64_t*)&dc->mem_dirty_tbl[wa] = dc->force_mem_dirty;
        THREADED_DISPATCH();
    }
#endif

    *(uint64_t*)&dc->mem_dirty_tbl[wa] = 0;
    THREADED_DISPATCH();

rt_mem_hd:
    wa = DEQ_FROM_ADDR();
    hdaddr = DEQ_FROM_ADDR();
    l = DEQ_FROM_ADDR();
    copy_contamination_mem_hd(dc, wa, hdaddr, l);
    THREADED_DISPATCH();

rt_hd_mem:
    ra = DEQ_FROM_ADDR();
    hdaddr = DEQ_FROM_ADDR();
    l = DEQ_FROM_ADDR();
    copy_contamination_hd_mem(dc, hdaddr, ra, l);
    THREADED_DISPATCH();

rt_rec_contaminate_mem_or:
    wa = DEQ_FROM_ADDR();
    j = ((*(uint64_t*)&rec) & 0x000000000000ff00) >> 8;
    l = ((*(uint64_t*)&rec) & 0x0000ffffffff0000) >> 16;
    for(i = 0 ; i < l ; i++)
        set_mem_dirty(dc, wa + i, j, 1);
    THREADED_DISPATCH();

rt_rec_contaminate_mem_and:
    wa = DEQ_FROM_ADDR();
    j = ((*(uint64_t*)&rec) & 0x000000000000ff00) >> 8;
    l = ((*(uint64_t*)&rec) & 0x0000ffffffff0000) >> 16;
    for(i = 0 ; i < l ; i++)
        and_mem_dirty(dc, wa + i, j, 1);
    THREADED_DISPATCH();

rt_rec_contaminate_hd_or:
    hdaddr = DEQ_FROM_ADDR();
    l      = DEQ_FROM_ADDR();

    j = ((*(uint64_t*)&rec) & 0x000000000000ff00) >> 8;
    for(i = 0 ; i < l ; i++)
        set_hd_dirty_or(dc, hdaddr + i, j);
    THREADED_DISPATCH();

rt_rec_contaminate_hd_and:
    hdaddr = DEQ_FROM_ADDR();
    l      = DEQ_FROM_ADDR();

    j = ((*(uint64_t*)&rec) & 0x000000000000ff00) >> 8;
    for(i = 0 ; i < l ; i++)
        set_hd_dirty_and(dc, hdaddr + i, j);
    THREADED_DISPATCH();

rt_rec_clear_mem:
    wa = DEQ_FROM_ADDR();
    l  = DEQ_FROM_ADDR();

    for(i = 0; i < l; i++)
        set_mem_dirty(dc, wa + i, 0, 0);
    THREADED_DISPATCH();

rt_rec_block_begin:
#if defined(CONFIG_TAINT_DIRTY_INS_OUTPUT)
    dc->phyeip = DEQ_FROM_CODE();

    /* We only check the first 4 bytes of the first instruction in this code block */
    uint32_t tt = *(uint32_t*)&dc->mem_dirty_tbl[dc->phyeip];
    if(tt) {
        uint32_t ss = ((tt & 0xff000000) >> 24) |
                      ((tt & 0xff0000) >> 16) |
                      ((tt & 0xff00) >> 8) |
                      ((tt & 0xff));
#if defined(CONFIG_SET_BIT7_ON_DIRTY_INS_OUTPUT)
        ss |= (1 << 7);
#endif
        tt = (ss << 24) | (ss << 16) | (ss << 8) | ss;
    }
    dc->force_mem_dirty = tt;
#endif
    THREADED_DISPATCH();
