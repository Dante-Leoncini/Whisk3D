-- año, señal, canción: la ñ y las tildes en el editor
function actualizar(dt)
    local x, y = posPx(yo())
    if tecla("arriba") then
        y = y - 200 * dt

        if y < 0 then
            y = 0
        end
    end
    setPosPx(yo(), x, y)
end
