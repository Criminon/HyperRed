@@SpecialTable equ 0x0815FD60
.macro special,index
    .org @@SpecialTable + (4 * index)
.endmacro


@@ScriptCommandsTable equ 0x815F9B4
.macro script_cmd,index
    .org @@ScriptCommandsTable + (4 * index)
.endmacro

