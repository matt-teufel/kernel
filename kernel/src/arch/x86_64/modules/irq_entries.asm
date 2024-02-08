extern irq_dispatch


glue: 
    push rax
    push rcx
    push rdx
    push rsi
    push r8
    push r9
    push r10
    push r11
    call irq_dispatch 
    pop r11 
    pop r10
    pop r9
    pop r8
    pop rsi
    pop rdx
    pop rcx
    pop rax
    pop rdi
    add rsp, 8 #pop the error code 
    iretq 

section .text
	global irq_entry_0
	global irq_entry_1
	global irq_entry_2
	global irq_entry_3
	global irq_entry_4
	global irq_entry_5
	global irq_entry_6
	global irq_entry_7
	global irq_entry_8
	global irq_entry_9
	global irq_entry_10
	global irq_entry_11
	global irq_entry_12
	global irq_entry_13
	global irq_entry_14
	global irq_entry_15
	global irq_entry_16
	global irq_entry_17
	global irq_entry_18
	global irq_entry_19
	global irq_entry_20
	global irq_entry_21
	global irq_entry_22
	global irq_entry_23
	global irq_entry_24
	global irq_entry_25
	global irq_entry_26
	global irq_entry_27
	global irq_entry_28
	global irq_entry_29
	global irq_entry_30
	global irq_entry_31
	global irq_entry_32
	global irq_entry_33
	global irq_entry_34
	global irq_entry_35
	global irq_entry_36
	global irq_entry_37
	global irq_entry_38
	global irq_entry_39
	global irq_entry_40
	global irq_entry_41
	global irq_entry_42
	global irq_entry_43
	global irq_entry_44
	global irq_entry_45
	global irq_entry_46
	global irq_entry_47
	global irq_entry_48
	global irq_entry_49
	global irq_entry_50
	global irq_entry_51
	global irq_entry_52
	global irq_entry_53
	global irq_entry_54
	global irq_entry_55
	global irq_entry_56
	global irq_entry_57
	global irq_entry_58
	global irq_entry_59
	global irq_entry_60
	global irq_entry_61
	global irq_entry_62
	global irq_entry_63
	global irq_entry_64
	global irq_entry_65
	global irq_entry_66
	global irq_entry_67
	global irq_entry_68
	global irq_entry_69
	global irq_entry_70
	global irq_entry_71
	global irq_entry_72
	global irq_entry_73
	global irq_entry_74
	global irq_entry_75
	global irq_entry_76
	global irq_entry_77
	global irq_entry_78
	global irq_entry_79
	global irq_entry_80
	global irq_entry_81
	global irq_entry_82
	global irq_entry_83
	global irq_entry_84
	global irq_entry_85
	global irq_entry_86
	global irq_entry_87
	global irq_entry_88
	global irq_entry_89
	global irq_entry_90
	global irq_entry_91
	global irq_entry_92
	global irq_entry_93
	global irq_entry_94
	global irq_entry_95
	global irq_entry_96
	global irq_entry_97
	global irq_entry_98
	global irq_entry_99
	global irq_entry_100
	global irq_entry_101
	global irq_entry_102
	global irq_entry_103
	global irq_entry_104
	global irq_entry_105
	global irq_entry_106
	global irq_entry_107
	global irq_entry_108
	global irq_entry_109
	global irq_entry_110
	global irq_entry_111
	global irq_entry_112
	global irq_entry_113
	global irq_entry_114
	global irq_entry_115
	global irq_entry_116
	global irq_entry_117
	global irq_entry_118
	global irq_entry_119
	global irq_entry_120
	global irq_entry_121
	global irq_entry_122
	global irq_entry_123
	global irq_entry_124
	global irq_entry_125
	global irq_entry_126
	global irq_entry_127
	global irq_entry_128
	global irq_entry_129
	global irq_entry_130
	global irq_entry_131
	global irq_entry_132
	global irq_entry_133
	global irq_entry_134
	global irq_entry_135
	global irq_entry_136
	global irq_entry_137
	global irq_entry_138
	global irq_entry_139
	global irq_entry_140
	global irq_entry_141
	global irq_entry_142
	global irq_entry_143
	global irq_entry_144
	global irq_entry_145
	global irq_entry_146
	global irq_entry_147
	global irq_entry_148
	global irq_entry_149
	global irq_entry_150
	global irq_entry_151
	global irq_entry_152
	global irq_entry_153
	global irq_entry_154
	global irq_entry_155
	global irq_entry_156
	global irq_entry_157
	global irq_entry_158
	global irq_entry_159
	global irq_entry_160
	global irq_entry_161
	global irq_entry_162
	global irq_entry_163
	global irq_entry_164
	global irq_entry_165
	global irq_entry_166
	global irq_entry_167
	global irq_entry_168
	global irq_entry_169
	global irq_entry_170
	global irq_entry_171
	global irq_entry_172
	global irq_entry_173
	global irq_entry_174
	global irq_entry_175
	global irq_entry_176
	global irq_entry_177
	global irq_entry_178
	global irq_entry_179
	global irq_entry_180
	global irq_entry_181
	global irq_entry_182
	global irq_entry_183
	global irq_entry_184
	global irq_entry_185
	global irq_entry_186
	global irq_entry_187
	global irq_entry_188
	global irq_entry_189
	global irq_entry_190
	global irq_entry_191
	global irq_entry_192
	global irq_entry_193
	global irq_entry_194
	global irq_entry_195
	global irq_entry_196
	global irq_entry_197
	global irq_entry_198
	global irq_entry_199
	global irq_entry_200
	global irq_entry_201
	global irq_entry_202
	global irq_entry_203
	global irq_entry_204
	global irq_entry_205
	global irq_entry_206
	global irq_entry_207
	global irq_entry_208
	global irq_entry_209
	global irq_entry_210
	global irq_entry_211
	global irq_entry_212
	global irq_entry_213
	global irq_entry_214
	global irq_entry_215
	global irq_entry_216
	global irq_entry_217
	global irq_entry_218
	global irq_entry_219
	global irq_entry_220
	global irq_entry_221
	global irq_entry_222
	global irq_entry_223
	global irq_entry_224
	global irq_entry_225
	global irq_entry_226
	global irq_entry_227
	global irq_entry_228
	global irq_entry_229
	global irq_entry_230
	global irq_entry_231
	global irq_entry_232
	global irq_entry_233
	global irq_entry_234
	global irq_entry_235
	global irq_entry_236
	global irq_entry_237
	global irq_entry_238
	global irq_entry_239
	global irq_entry_240
	global irq_entry_241
	global irq_entry_242
	global irq_entry_243
	global irq_entry_244
	global irq_entry_245
	global irq_entry_246
	global irq_entry_247
	global irq_entry_248
	global irq_entry_249
	global irq_entry_250
	global irq_entry_251
	global irq_entry_252
	global irq_entry_253
	global irq_entry_254
	global irq_entry_255

irq_entry_0:
    push rdi
    push rdi 
    mov rdi, 0
    jmp glue 

irq_entry_1:
    push rdi
    push rdi 
    mov rdi, 1
    jmp glue 

irq_entry_2:
    push rdi
    push rdi 
    mov rdi, 2
    jmp glue 

irq_entry_3:
    push rdi
    push rdi 
    mov rdi, 3
    jmp glue 

irq_entry_4:
    push rdi
    push rdi 
    mov rdi, 4
    jmp glue 

irq_entry_5:
    push rdi
    push rdi 
    mov rdi, 5
    jmp glue 

irq_entry_6:
    push rdi
    push rdi 
    mov rdi, 6
    jmp glue 

irq_entry_7:
    push rdi
    push rdi 
    mov rdi, 7
    jmp glue 

irq_entry_8:
    push rdi
    mov rdi, 8
    jmp glue

irq_entry_9:
    push rdi
    push rdi 
    mov rdi, 9
    jmp glue 

irq_entry_10:
    push rdi
    mov rdi, 10
    jmp glue

irq_entry_11:
    push rdi
    mov rdi, 11
    jmp glue

irq_entry_12:
    push rdi
    mov rdi, 12
    jmp glue

irq_entry_13:
    push rdi
    mov rdi, 13
    jmp glue

irq_entry_14:
    push rdi
    mov rdi, 14
    jmp glue

irq_entry_15:
    push rdi
    push rdi 
    mov rdi, 15
    jmp glue 

irq_entry_16:
    push rdi
    push rdi 
    mov rdi, 16
    jmp glue 

irq_entry_17:
    push rdi
    push rdi 
    mov rdi, 17
    jmp glue 

irq_entry_18:
    push rdi
    push rdi 
    mov rdi, 18
    jmp glue 

irq_entry_19:
    push rdi
    push rdi 
    mov rdi, 19
    jmp glue 

irq_entry_20:
    push rdi
    push rdi 
    mov rdi, 20
    jmp glue 

irq_entry_21:
    push rdi
    push rdi 
    mov rdi, 21
    jmp glue 

irq_entry_22:
    push rdi
    push rdi 
    mov rdi, 22
    jmp glue 

irq_entry_23:
    push rdi
    push rdi 
    mov rdi, 23
    jmp glue 

irq_entry_24:
    push rdi
    push rdi 
    mov rdi, 24
    jmp glue 

irq_entry_25:
    push rdi
    push rdi 
    mov rdi, 25
    jmp glue 

irq_entry_26:
    push rdi
    push rdi 
    mov rdi, 26
    jmp glue 

irq_entry_27:
    push rdi
    push rdi 
    mov rdi, 27
    jmp glue 

irq_entry_28:
    push rdi
    push rdi 
    mov rdi, 28
    jmp glue 

irq_entry_29:
    push rdi
    push rdi 
    mov rdi, 29
    jmp glue 

irq_entry_30:
    push rdi
    push rdi 
    mov rdi, 30
    jmp glue 

irq_entry_31:
    push rdi
    push rdi 
    mov rdi, 31
    jmp glue 

irq_entry_32:
    push rdi
    push rdi 
    mov rdi, 32
    jmp glue 

irq_entry_33:
    push rdi
    push rdi 
    mov rdi, 33
    jmp glue 

irq_entry_34:
    push rdi
    push rdi 
    mov rdi, 34
    jmp glue 

irq_entry_35:
    push rdi
    push rdi 
    mov rdi, 35
    jmp glue 

irq_entry_36:
    push rdi
    push rdi 
    mov rdi, 36
    jmp glue 

irq_entry_37:
    push rdi
    push rdi 
    mov rdi, 37
    jmp glue 

irq_entry_38:
    push rdi
    push rdi 
    mov rdi, 38
    jmp glue 

irq_entry_39:
    push rdi
    push rdi 
    mov rdi, 39
    jmp glue 

irq_entry_40:
    push rdi
    push rdi 
    mov rdi, 40
    jmp glue 

irq_entry_41:
    push rdi
    push rdi 
    mov rdi, 41
    jmp glue 

irq_entry_42:
    push rdi
    push rdi 
    mov rdi, 42
    jmp glue 

irq_entry_43:
    push rdi
    push rdi 
    mov rdi, 43
    jmp glue 

irq_entry_44:
    push rdi
    push rdi 
    mov rdi, 44
    jmp glue 

irq_entry_45:
    push rdi
    push rdi 
    mov rdi, 45
    jmp glue 

irq_entry_46:
    push rdi
    push rdi 
    mov rdi, 46
    jmp glue 

irq_entry_47:
    push rdi
    push rdi 
    mov rdi, 47
    jmp glue 

irq_entry_48:
    push rdi
    push rdi 
    mov rdi, 48
    jmp glue 

irq_entry_49:
    push rdi
    push rdi 
    mov rdi, 49
    jmp glue 

irq_entry_50:
    push rdi
    push rdi 
    mov rdi, 50
    jmp glue 

irq_entry_51:
    push rdi
    push rdi 
    mov rdi, 51
    jmp glue 

irq_entry_52:
    push rdi
    push rdi 
    mov rdi, 52
    jmp glue 

irq_entry_53:
    push rdi
    push rdi 
    mov rdi, 53
    jmp glue 

irq_entry_54:
    push rdi
    push rdi 
    mov rdi, 54
    jmp glue 

irq_entry_55:
    push rdi
    push rdi 
    mov rdi, 55
    jmp glue 

irq_entry_56:
    push rdi
    push rdi 
    mov rdi, 56
    jmp glue 

irq_entry_57:
    push rdi
    push rdi 
    mov rdi, 57
    jmp glue 

irq_entry_58:
    push rdi
    push rdi 
    mov rdi, 58
    jmp glue 

irq_entry_59:
    push rdi
    push rdi 
    mov rdi, 59
    jmp glue 

irq_entry_60:
    push rdi
    push rdi 
    mov rdi, 60
    jmp glue 

irq_entry_61:
    push rdi
    push rdi 
    mov rdi, 61
    jmp glue 

irq_entry_62:
    push rdi
    push rdi 
    mov rdi, 62
    jmp glue 

irq_entry_63:
    push rdi
    push rdi 
    mov rdi, 63
    jmp glue 

irq_entry_64:
    push rdi
    push rdi 
    mov rdi, 64
    jmp glue 

irq_entry_65:
    push rdi
    push rdi 
    mov rdi, 65
    jmp glue 

irq_entry_66:
    push rdi
    push rdi 
    mov rdi, 66
    jmp glue 

irq_entry_67:
    push rdi
    push rdi 
    mov rdi, 67
    jmp glue 

irq_entry_68:
    push rdi
    push rdi 
    mov rdi, 68
    jmp glue 

irq_entry_69:
    push rdi
    push rdi 
    mov rdi, 69
    jmp glue 

irq_entry_70:
    push rdi
    push rdi 
    mov rdi, 70
    jmp glue 

irq_entry_71:
    push rdi
    push rdi 
    mov rdi, 71
    jmp glue 

irq_entry_72:
    push rdi
    push rdi 
    mov rdi, 72
    jmp glue 

irq_entry_73:
    push rdi
    push rdi 
    mov rdi, 73
    jmp glue 

irq_entry_74:
    push rdi
    push rdi 
    mov rdi, 74
    jmp glue 

irq_entry_75:
    push rdi
    push rdi 
    mov rdi, 75
    jmp glue 

irq_entry_76:
    push rdi
    push rdi 
    mov rdi, 76
    jmp glue 

irq_entry_77:
    push rdi
    push rdi 
    mov rdi, 77
    jmp glue 

irq_entry_78:
    push rdi
    push rdi 
    mov rdi, 78
    jmp glue 

irq_entry_79:
    push rdi
    push rdi 
    mov rdi, 79
    jmp glue 

irq_entry_80:
    push rdi
    push rdi 
    mov rdi, 80
    jmp glue 

irq_entry_81:
    push rdi
    push rdi 
    mov rdi, 81
    jmp glue 

irq_entry_82:
    push rdi
    push rdi 
    mov rdi, 82
    jmp glue 

irq_entry_83:
    push rdi
    push rdi 
    mov rdi, 83
    jmp glue 

irq_entry_84:
    push rdi
    push rdi 
    mov rdi, 84
    jmp glue 

irq_entry_85:
    push rdi
    push rdi 
    mov rdi, 85
    jmp glue 

irq_entry_86:
    push rdi
    push rdi 
    mov rdi, 86
    jmp glue 

irq_entry_87:
    push rdi
    push rdi 
    mov rdi, 87
    jmp glue 

irq_entry_88:
    push rdi
    push rdi 
    mov rdi, 88
    jmp glue 

irq_entry_89:
    push rdi
    push rdi 
    mov rdi, 89
    jmp glue 

irq_entry_90:
    push rdi
    push rdi 
    mov rdi, 90
    jmp glue 

irq_entry_91:
    push rdi
    push rdi 
    mov rdi, 91
    jmp glue 

irq_entry_92:
    push rdi
    push rdi 
    mov rdi, 92
    jmp glue 

irq_entry_93:
    push rdi
    push rdi 
    mov rdi, 93
    jmp glue 

irq_entry_94:
    push rdi
    push rdi 
    mov rdi, 94
    jmp glue 

irq_entry_95:
    push rdi
    push rdi 
    mov rdi, 95
    jmp glue 

irq_entry_96:
    push rdi
    push rdi 
    mov rdi, 96
    jmp glue 

irq_entry_97:
    push rdi
    push rdi 
    mov rdi, 97
    jmp glue 

irq_entry_98:
    push rdi
    push rdi 
    mov rdi, 98
    jmp glue 

irq_entry_99:
    push rdi
    push rdi 
    mov rdi, 99
    jmp glue 

irq_entry_100:
    push rdi
    push rdi 
    mov rdi, 100
    jmp glue 

irq_entry_101:
    push rdi
    push rdi 
    mov rdi, 101
    jmp glue 

irq_entry_102:
    push rdi
    push rdi 
    mov rdi, 102
    jmp glue 

irq_entry_103:
    push rdi
    push rdi 
    mov rdi, 103
    jmp glue 

irq_entry_104:
    push rdi
    push rdi 
    mov rdi, 104
    jmp glue 

irq_entry_105:
    push rdi
    push rdi 
    mov rdi, 105
    jmp glue 

irq_entry_106:
    push rdi
    push rdi 
    mov rdi, 106
    jmp glue 

irq_entry_107:
    push rdi
    push rdi 
    mov rdi, 107
    jmp glue 

irq_entry_108:
    push rdi
    push rdi 
    mov rdi, 108
    jmp glue 

irq_entry_109:
    push rdi
    push rdi 
    mov rdi, 109
    jmp glue 

irq_entry_110:
    push rdi
    push rdi 
    mov rdi, 110
    jmp glue 

irq_entry_111:
    push rdi
    push rdi 
    mov rdi, 111
    jmp glue 

irq_entry_112:
    push rdi
    push rdi 
    mov rdi, 112
    jmp glue 

irq_entry_113:
    push rdi
    push rdi 
    mov rdi, 113
    jmp glue 

irq_entry_114:
    push rdi
    push rdi 
    mov rdi, 114
    jmp glue 

irq_entry_115:
    push rdi
    push rdi 
    mov rdi, 115
    jmp glue 

irq_entry_116:
    push rdi
    push rdi 
    mov rdi, 116
    jmp glue 

irq_entry_117:
    push rdi
    push rdi 
    mov rdi, 117
    jmp glue 

irq_entry_118:
    push rdi
    push rdi 
    mov rdi, 118
    jmp glue 

irq_entry_119:
    push rdi
    push rdi 
    mov rdi, 119
    jmp glue 

irq_entry_120:
    push rdi
    push rdi 
    mov rdi, 120
    jmp glue 

irq_entry_121:
    push rdi
    push rdi 
    mov rdi, 121
    jmp glue 

irq_entry_122:
    push rdi
    push rdi 
    mov rdi, 122
    jmp glue 

irq_entry_123:
    push rdi
    push rdi 
    mov rdi, 123
    jmp glue 

irq_entry_124:
    push rdi
    push rdi 
    mov rdi, 124
    jmp glue 

irq_entry_125:
    push rdi
    push rdi 
    mov rdi, 125
    jmp glue 

irq_entry_126:
    push rdi
    push rdi 
    mov rdi, 126
    jmp glue 

irq_entry_127:
    push rdi
    push rdi 
    mov rdi, 127
    jmp glue 

irq_entry_128:
    push rdi
    push rdi 
    mov rdi, 128
    jmp glue 

irq_entry_129:
    push rdi
    push rdi 
    mov rdi, 129
    jmp glue 

irq_entry_130:
    push rdi
    push rdi 
    mov rdi, 130
    jmp glue 

irq_entry_131:
    push rdi
    push rdi 
    mov rdi, 131
    jmp glue 

irq_entry_132:
    push rdi
    push rdi 
    mov rdi, 132
    jmp glue 

irq_entry_133:
    push rdi
    push rdi 
    mov rdi, 133
    jmp glue 

irq_entry_134:
    push rdi
    push rdi 
    mov rdi, 134
    jmp glue 

irq_entry_135:
    push rdi
    push rdi 
    mov rdi, 135
    jmp glue 

irq_entry_136:
    push rdi
    push rdi 
    mov rdi, 136
    jmp glue 

irq_entry_137:
    push rdi
    push rdi 
    mov rdi, 137
    jmp glue 

irq_entry_138:
    push rdi
    push rdi 
    mov rdi, 138
    jmp glue 

irq_entry_139:
    push rdi
    push rdi 
    mov rdi, 139
    jmp glue 

irq_entry_140:
    push rdi
    push rdi 
    mov rdi, 140
    jmp glue 

irq_entry_141:
    push rdi
    push rdi 
    mov rdi, 141
    jmp glue 

irq_entry_142:
    push rdi
    push rdi 
    mov rdi, 142
    jmp glue 

irq_entry_143:
    push rdi
    push rdi 
    mov rdi, 143
    jmp glue 

irq_entry_144:
    push rdi
    push rdi 
    mov rdi, 144
    jmp glue 

irq_entry_145:
    push rdi
    push rdi 
    mov rdi, 145
    jmp glue 

irq_entry_146:
    push rdi
    push rdi 
    mov rdi, 146
    jmp glue 

irq_entry_147:
    push rdi
    push rdi 
    mov rdi, 147
    jmp glue 

irq_entry_148:
    push rdi
    push rdi 
    mov rdi, 148
    jmp glue 

irq_entry_149:
    push rdi
    push rdi 
    mov rdi, 149
    jmp glue 

irq_entry_150:
    push rdi
    push rdi 
    mov rdi, 150
    jmp glue 

irq_entry_151:
    push rdi
    push rdi 
    mov rdi, 151
    jmp glue 

irq_entry_152:
    push rdi
    push rdi 
    mov rdi, 152
    jmp glue 

irq_entry_153:
    push rdi
    push rdi 
    mov rdi, 153
    jmp glue 

irq_entry_154:
    push rdi
    push rdi 
    mov rdi, 154
    jmp glue 

irq_entry_155:
    push rdi
    push rdi 
    mov rdi, 155
    jmp glue 

irq_entry_156:
    push rdi
    push rdi 
    mov rdi, 156
    jmp glue 

irq_entry_157:
    push rdi
    push rdi 
    mov rdi, 157
    jmp glue 

irq_entry_158:
    push rdi
    push rdi 
    mov rdi, 158
    jmp glue 

irq_entry_159:
    push rdi
    push rdi 
    mov rdi, 159
    jmp glue 

irq_entry_160:
    push rdi
    push rdi 
    mov rdi, 160
    jmp glue 

irq_entry_161:
    push rdi
    push rdi 
    mov rdi, 161
    jmp glue 

irq_entry_162:
    push rdi
    push rdi 
    mov rdi, 162
    jmp glue 

irq_entry_163:
    push rdi
    push rdi 
    mov rdi, 163
    jmp glue 

irq_entry_164:
    push rdi
    push rdi 
    mov rdi, 164
    jmp glue 

irq_entry_165:
    push rdi
    push rdi 
    mov rdi, 165
    jmp glue 

irq_entry_166:
    push rdi
    push rdi 
    mov rdi, 166
    jmp glue 

irq_entry_167:
    push rdi
    push rdi 
    mov rdi, 167
    jmp glue 

irq_entry_168:
    push rdi
    push rdi 
    mov rdi, 168
    jmp glue 

irq_entry_169:
    push rdi
    push rdi 
    mov rdi, 169
    jmp glue 

irq_entry_170:
    push rdi
    push rdi 
    mov rdi, 170
    jmp glue 

irq_entry_171:
    push rdi
    push rdi 
    mov rdi, 171
    jmp glue 

irq_entry_172:
    push rdi
    push rdi 
    mov rdi, 172
    jmp glue 

irq_entry_173:
    push rdi
    push rdi 
    mov rdi, 173
    jmp glue 

irq_entry_174:
    push rdi
    push rdi 
    mov rdi, 174
    jmp glue 

irq_entry_175:
    push rdi
    push rdi 
    mov rdi, 175
    jmp glue 

irq_entry_176:
    push rdi
    push rdi 
    mov rdi, 176
    jmp glue 

irq_entry_177:
    push rdi
    push rdi 
    mov rdi, 177
    jmp glue 

irq_entry_178:
    push rdi
    push rdi 
    mov rdi, 178
    jmp glue 

irq_entry_179:
    push rdi
    push rdi 
    mov rdi, 179
    jmp glue 

irq_entry_180:
    push rdi
    push rdi 
    mov rdi, 180
    jmp glue 

irq_entry_181:
    push rdi
    push rdi 
    mov rdi, 181
    jmp glue 

irq_entry_182:
    push rdi
    push rdi 
    mov rdi, 182
    jmp glue 

irq_entry_183:
    push rdi
    push rdi 
    mov rdi, 183
    jmp glue 

irq_entry_184:
    push rdi
    push rdi 
    mov rdi, 184
    jmp glue 

irq_entry_185:
    push rdi
    push rdi 
    mov rdi, 185
    jmp glue 

irq_entry_186:
    push rdi
    push rdi 
    mov rdi, 186
    jmp glue 

irq_entry_187:
    push rdi
    push rdi 
    mov rdi, 187
    jmp glue 

irq_entry_188:
    push rdi
    push rdi 
    mov rdi, 188
    jmp glue 

irq_entry_189:
    push rdi
    push rdi 
    mov rdi, 189
    jmp glue 

irq_entry_190:
    push rdi
    push rdi 
    mov rdi, 190
    jmp glue 

irq_entry_191:
    push rdi
    push rdi 
    mov rdi, 191
    jmp glue 

irq_entry_192:
    push rdi
    push rdi 
    mov rdi, 192
    jmp glue 

irq_entry_193:
    push rdi
    push rdi 
    mov rdi, 193
    jmp glue 

irq_entry_194:
    push rdi
    push rdi 
    mov rdi, 194
    jmp glue 

irq_entry_195:
    push rdi
    push rdi 
    mov rdi, 195
    jmp glue 

irq_entry_196:
    push rdi
    push rdi 
    mov rdi, 196
    jmp glue 

irq_entry_197:
    push rdi
    push rdi 
    mov rdi, 197
    jmp glue 

irq_entry_198:
    push rdi
    push rdi 
    mov rdi, 198
    jmp glue 

irq_entry_199:
    push rdi
    push rdi 
    mov rdi, 199
    jmp glue 

irq_entry_200:
    push rdi
    push rdi 
    mov rdi, 200
    jmp glue 

irq_entry_201:
    push rdi
    push rdi 
    mov rdi, 201
    jmp glue 

irq_entry_202:
    push rdi
    push rdi 
    mov rdi, 202
    jmp glue 

irq_entry_203:
    push rdi
    push rdi 
    mov rdi, 203
    jmp glue 

irq_entry_204:
    push rdi
    push rdi 
    mov rdi, 204
    jmp glue 

irq_entry_205:
    push rdi
    push rdi 
    mov rdi, 205
    jmp glue 

irq_entry_206:
    push rdi
    push rdi 
    mov rdi, 206
    jmp glue 

irq_entry_207:
    push rdi
    push rdi 
    mov rdi, 207
    jmp glue 

irq_entry_208:
    push rdi
    push rdi 
    mov rdi, 208
    jmp glue 

irq_entry_209:
    push rdi
    push rdi 
    mov rdi, 209
    jmp glue 

irq_entry_210:
    push rdi
    push rdi 
    mov rdi, 210
    jmp glue 

irq_entry_211:
    push rdi
    push rdi 
    mov rdi, 211
    jmp glue 

irq_entry_212:
    push rdi
    push rdi 
    mov rdi, 212
    jmp glue 

irq_entry_213:
    push rdi
    push rdi 
    mov rdi, 213
    jmp glue 

irq_entry_214:
    push rdi
    push rdi 
    mov rdi, 214
    jmp glue 

irq_entry_215:
    push rdi
    push rdi 
    mov rdi, 215
    jmp glue 

irq_entry_216:
    push rdi
    push rdi 
    mov rdi, 216
    jmp glue 

irq_entry_217:
    push rdi
    push rdi 
    mov rdi, 217
    jmp glue 

irq_entry_218:
    push rdi
    push rdi 
    mov rdi, 218
    jmp glue 

irq_entry_219:
    push rdi
    push rdi 
    mov rdi, 219
    jmp glue 

irq_entry_220:
    push rdi
    push rdi 
    mov rdi, 220
    jmp glue 

irq_entry_221:
    push rdi
    push rdi 
    mov rdi, 221
    jmp glue 

irq_entry_222:
    push rdi
    push rdi 
    mov rdi, 222
    jmp glue 

irq_entry_223:
    push rdi
    push rdi 
    mov rdi, 223
    jmp glue 

irq_entry_224:
    push rdi
    push rdi 
    mov rdi, 224
    jmp glue 

irq_entry_225:
    push rdi
    push rdi 
    mov rdi, 225
    jmp glue 

irq_entry_226:
    push rdi
    push rdi 
    mov rdi, 226
    jmp glue 

irq_entry_227:
    push rdi
    push rdi 
    mov rdi, 227
    jmp glue 

irq_entry_228:
    push rdi
    push rdi 
    mov rdi, 228
    jmp glue 

irq_entry_229:
    push rdi
    push rdi 
    mov rdi, 229
    jmp glue 

irq_entry_230:
    push rdi
    push rdi 
    mov rdi, 230
    jmp glue 

irq_entry_231:
    push rdi
    push rdi 
    mov rdi, 231
    jmp glue 

irq_entry_232:
    push rdi
    push rdi 
    mov rdi, 232
    jmp glue 

irq_entry_233:
    push rdi
    push rdi 
    mov rdi, 233
    jmp glue 

irq_entry_234:
    push rdi
    push rdi 
    mov rdi, 234
    jmp glue 

irq_entry_235:
    push rdi
    push rdi 
    mov rdi, 235
    jmp glue 

irq_entry_236:
    push rdi
    push rdi 
    mov rdi, 236
    jmp glue 

irq_entry_237:
    push rdi
    push rdi 
    mov rdi, 237
    jmp glue 

irq_entry_238:
    push rdi
    push rdi 
    mov rdi, 238
    jmp glue 

irq_entry_239:
    push rdi
    push rdi 
    mov rdi, 239
    jmp glue 

irq_entry_240:
    push rdi
    push rdi 
    mov rdi, 240
    jmp glue 

irq_entry_241:
    push rdi
    push rdi 
    mov rdi, 241
    jmp glue 

irq_entry_242:
    push rdi
    push rdi 
    mov rdi, 242
    jmp glue 

irq_entry_243:
    push rdi
    push rdi 
    mov rdi, 243
    jmp glue 

irq_entry_244:
    push rdi
    push rdi 
    mov rdi, 244
    jmp glue 

irq_entry_245:
    push rdi
    push rdi 
    mov rdi, 245
    jmp glue 

irq_entry_246:
    push rdi
    push rdi 
    mov rdi, 246
    jmp glue 

irq_entry_247:
    push rdi
    push rdi 
    mov rdi, 247
    jmp glue 

irq_entry_248:
    push rdi
    push rdi 
    mov rdi, 248
    jmp glue 

irq_entry_249:
    push rdi
    push rdi 
    mov rdi, 249
    jmp glue 

irq_entry_250:
    push rdi
    push rdi 
    mov rdi, 250
    jmp glue 

irq_entry_251:
    push rdi
    push rdi 
    mov rdi, 251
    jmp glue 

irq_entry_252:
    push rdi
    push rdi 
    mov rdi, 252
    jmp glue 

irq_entry_253:
    push rdi
    push rdi 
    mov rdi, 253
    jmp glue 

irq_entry_254:
    push rdi
    push rdi 
    mov rdi, 254
    jmp glue 

irq_entry_255:
    push rdi
    push rdi 
    mov rdi, 255
    jmp glue 