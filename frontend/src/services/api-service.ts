import ky from "ky";

export abstract class ApiService {
    protected API = ky.create({
        prefixUrl: import.meta.env.VITE_API_URL,
    }).extend({
        headers: {
            "ngrok-skip-browser-warning": import.meta.env.VITE_SKIP_NGROK_WARNING,
        },
    });
}
