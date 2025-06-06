import { useState } from "react";
import { CameraIcon } from "@heroicons/react/24/outline";

const FlashCameraButton = () => {
    const [flash, setFlash] = useState(false);

    const handleFlash = () => {
        setFlash(true);
        setTimeout(() => setFlash(false), 300);
    };

    return (
        <>
            {flash && (
                <div className="fixed top-0 left-0 w-full h-full bg-white opacity-80 z-50 pointer-events-none" />
            )}
            <button
                onClick={handleFlash}
                className="p-2 hover:bg-gray-800 rounded"
                title="Фотоапарат"
            >
                <CameraIcon className="w-6 h-6 text-gray-300 hover:text-white" />
            </button>
        </>
    );
};

export default FlashCameraButton;
