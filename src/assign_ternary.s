          .text                         
          .globl main                   
          .align 2                      

          .text                         
main:                                   # function entry
          sw    ra, -4(sp)              
          sw    fp, -8(sp)              
          mv    fp, sp                  
          addi  sp, sp, -12             
__LL0:                                  
                                  # ü
          li    t0, 0                   
                                  # ü
                                  # ü
          li    t1, 1                   
          beqz  t1, __LL2               
          j     __LL1                   
__LL1:                                  
                                  # 
          li    t0, 2                   
                                  # 
          mv    t1, t0                  
                                  # (save modified registers before control flow changes)
          sw    t1, -12(fp)             # spill T3 from t1 to (fp-12)
          j     __LL3                   
__LL3:                                  
                                  # 
          lw    t0, -12(fp)             # load T3 from (fp-12) into t0
          mv    t1, t0                  
          mv    a0, t1                  
          mv    sp, fp                  
          lw    ra, -4(fp)              
          lw    fp, -8(fp)              
          ret                           
__LL2:                                  
                                  # ü
          li    t0, 3                   
                                  # ü
          mv    t1, t0                  
                                  # (save modified registers before control flow changes)
          sw    t1, -12(fp)             # spill T3 from t1 to (fp-12)
          j     __LL3                   
